struct tree
{
    int info;
    struct tree *esq, *dir;
};
typedef struct tree Tree;

struct pilha
{
    Tree *raiz;
    struct pilha *prox;
};
typedef struct pilha Pilha;

struct fila
{
    Tree *raiz;
    struct fila *prox;
};
typedef struct fila Fila;

int FisEmpty(Fila *inicio)
{
    return inicio == NULL;
}

void initF(Fila **inicio)
{
    *inicio == NULL;
}

void enqueue(Fila **inicio, Tree *raiz)
{
    Fila *novo = (Fila *)malloc(sizeof(Fila));
    novo->raiz = raiz;
    (*inicio)->prox = novo;
}

void dequeue(Fila **inicio, Tree **info)
{
    if (!FisEmpty(*inicio))
    {
        Fila *aux = *inicio;
        *info = (*inicio)->raiz;
        *inicio = (*inicio)->prox;
        free(aux);
    }
    else
    {
        *info = NULL;
    }
}

int isEmpty(Pilha *inicio)
{
    return inicio == NULL;
}

void initP(Pilha **inicio)
{
    *inicio = NULL;
}

void push(Pilha **inicio, Tree *raiz)
{
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    novo->raiz = raiz;
    novo->prox = *inicio;
    *inicio = novo;
}

void pop(Pilha **inicio, Tree **info)
{
    if (!isEmpty(*inicio))
    {
        Pilha *aux = *inicio;
        *info = (*inicio)->raiz;
        *inicio = (*inicio)->prox;
        free(aux);
    }
    else
    {
        *info = NULL;
    }
}

void init(Tree **raiz)
{
    *raiz = NULL;
}
// criar nÃ³
Tree *criaNo(int info)
{
    Tree *no = (Tree *)malloc(sizeof(Tree));
    no->info = info;
    no->esq = no->dir = NULL;
    return no;
}

// localizar nÃ³
void localizaNo(Tree *raiz, int info, Tree **pai)
{
    if (raiz != NULL)
    {
        if (info == raiz->info)
        {
            *pai = raiz;
        }
        else
        {
            localizaNo(raiz->esq, info, &*pai);
            if (*pai == NULL)
            {
                localizaNo(raiz->dir, info, &*pai);
            }
        }
    }
}

// inserir elemento na arvore
// void insere(Tree **raiz, int info, int infoPai, char lado)
//{
//     Tree *pai = NULL;
//     if (*raiz == NULL)
//         *raiz = criaNo(info);
//     else
//     {
//         localizaNo(*raiz, infoPai, &pai);
//         if (pai != NULL)
//         {
//             if (lado == 'd' && pai->dir == NULL)
//             {
//                 pai->dir = criaNo(info);
//             }
//             else if (lado == 'e' && pai->esq == NULL)
//             {
//                 pai->esq = criaNo(info);
//             }
//             else
//             {
//                 printf("lado ocupado\n");
//             }
//         }
//         else
//         {
//             printf("pai nao encontrado\n");
//         }
//     }
// }

// algoritimos de exibiÃ§Ã£o
void preOrd(Tree *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->info);
        preOrd(raiz->esq);
        preOrd(raiz->dir);
    }
}

void inOrd(Tree *raiz)
{
    if (raiz != NULL)
    {
        preOrd(raiz->esq);
        printf("%d ", raiz->info);
        preOrd(raiz->dir);
    }
}

void posOrd(Tree *raiz)
{
    if (raiz != NULL)
    {
        preOrd(raiz->esq);
        preOrd(raiz->dir);
        printf("%d ", raiz->info);
    }
}

void deletTree(Tree **raiz)
{
    if (*raiz != NULL)
    {
        deletTree(&(*raiz)->esq);
        deletTree(&(*raiz)->dir);
        free(*raiz);
    }
    *raiz = NULL;
}

// iterativo

void preOrdI(Tree *raiz)
{
    Pilha *P;
    initP(&P);
    push(&P, raiz);
    while (!isEmpty(P))
    {
        if (raiz != NULL)
        {
            pop(&P, &raiz);
            while (raiz != NULL)
            {
                printf("%d ", raiz->info);
                push(&P, raiz);
                raiz = raiz->esq;
            }
        }

        pop(&P, &raiz);
        raiz = raiz->dir;
        if (raiz != NULL)
            push(&P, raiz);
    }
}

void posOrdI(Tree *raiz)
{
    Pilha *P, *P2;
    initP(&P);
    initP(&P2);
    push(&P, raiz);
    while (!isEmpty(P))
    {
        if (raiz != NULL)
        {
            pop(&P, &raiz);
            while (raiz != NULL)
            {
                push(&P, raiz);
                push(&P2, raiz);
                raiz = raiz->esq;
            }
        }

        pop(&P, &raiz);
        raiz = raiz->dir;
        if (raiz != NULL)
            push(&P, raiz);
    }
    while (!isEmpty(P2))
    {
        pop(&P2, &raiz);
        printf("%d ", raiz->info);
    }
}

void BuscaNoI(Tree *raiz, Tree **e, Tree **pai, int info)
{
    *e = *pai = raiz;
    while (*e != NULL && (*e)->info != info)
    {
        *pai = *e;
        if (info < (*e)->info)
        {
            (*e) = (*e)->esq;
        }
        else
        {
            *e = (*e)->dir;
        }
    }
}

Tree *buscaNoR(Tree *raiz, int info)
{
    if (raiz == NULL)
        return NULL;
    if (raiz->info == info)

        return raiz;
    else if (info < raiz->info)
        return buscaNoR(raiz->esq, raiz->info);
    else
        return buscaNoR(raiz->dir, raiz->info);
}

void insereABB(Tree **raiz, int info)
{
    Tree *aux, *ant;
    if (*raiz == NULL)
    {
        *raiz = criaNo(info);
    }
    else
    {
        aux = *raiz;
        while (aux != NULL)
        {
            ant = aux;
            if (info < aux->info)
            {
                aux = aux->esq;
            }
            else
            {
                aux = aux->dir;
            }
        }
        if (info < ant->info)
            ant->esq = criaNo(info);
        else
            ant->dir = criaNo(info);
    }
}

void printTree(Tree *raiz, int nivel)
{
    int i = 0;
    if (raiz != NULL)
    {
        printTree(raiz->dir, nivel + 1);

        for (i = 0; i < nivel; i++)
        {
            printf("    ");
        }
        printf("%d\n", raiz->info);

        printTree(raiz->esq, nivel + 1);
    }
}

void exclusaoABBI(Tree **raiz, Tree *e, Tree *pai, char lado)
{
    Tree *paisub, *sub;
    int aux;
    if (e->esq == NULL && e->dir == NULL) // eh folha
    {
        if (e != pai)
        {
            if (e->info > pai->info)
                pai->dir = NULL;
            else
                pai->esq = NULL;
        }
        else
        {
            *raiz = NULL;
        }
        free(e);
    }
    else if (e->esq == NULL || e->dir == NULL) // e tem 1 filho 2
    {
        if (e->info != pai->info) // 2.1
        {
            if (e->info > pai->info) // 2.1.1
            {
                if (e->esq != NULL) // 2.1.1.1
                {
                    pai->dir = e->esq;
                    free(e);
                }
                else if (e->dir != NULL) // 2.1.1.2
                {
                    pai->dir = e->dir;
                    free(e);
                }
            }
            else if (e->info < pai->info) // 2.1.2
            {
                if (e->esq != NULL) // 2.1.2.1
                {
                    pai->esq = e->esq;
                    free(e);
                }
                else if (e->dir != NULL) // 2.1.2.2
                {
                    pai->dir = e->dir;
                    free(e);
                }
            }
        }
        else if (e->info == pai->info) // 2.2
        {
            if (e->esq != NULL) // 2.2.1
            {
                *raiz = e->esq;
                free(e);
            }
            else if (e->dir != NULL) // 2.2.2
            {
                *raiz = e->dir;
                free(e);
            }
        }
    }
    else
    {
        if (lado == 'd') // substituto de d
        {
            paisub = e;
            sub = e->dir;
            while (sub->esq != NULL)
            {
                paisub = sub;
                sub = sub->dir;
            }
            aux = sub->info;
            exclusaoABBI(&*raiz, sub, paisub, 'd');
            e->info = aux;
        }
        else // lado == e substituto de e
        {
            paisub = e;
            sub = e->esq;
            while (sub->dir != NULL)
            {
                paisub = sub;
                sub = sub->esq;
            }
            aux = sub->info;
            exclusaoABBI(&*raiz, sub, paisub, 'e');
            e->info = aux;
        }
    }
}

void quantNo(Tree *P, int *qDir)
{
}

void balanceamentoABB(Tree **raiz)
{
    int qDir, qEsq, FB, aux;
    Tree *p, *pai, *e;
    Fila *F;
    init(&F);
    enqueue(&F, *raiz);
    while (!FisEmpty(F))
    {
        dequeue(&F, &p);
        do
        {
            qDir = qEsq = 0;
            quantNo(p->dir, &qDir);
            quantNo(p->dir, &qEsq);
            FB = qDir - qEsq;
            if (FB < -1 || FB > 1) // desbalanceado
            {
                aux = p->info;
                BuscaNoI(*raiz, &e, &pai, p->info);
                if (p->esq == NULL)
                {
                    p = p->dir;
                }
                else if (p->dir == NULL)
                {
                    p = p->esq;
                }

                if (FB > 0)
                    exclusaoABBI(&*raiz, e, pai, 'd');
                else
                    exclusaoABBI(&*raiz, e, pai, 'e');
                insereABB(&*raiz, aux);
            }
        } while (FB < -1 || FB > 1);
        if (p->esq != NULL)
        {
            enqueue(&F, p->esq);
        }
        if (p->dir != NULL)
        {
            enqueue(&F, p->dir);
        }
    }
}

int calculatealturaIterative(Tree *root)
{

    int altura = -1, tam, levelAt;
    Pilha *P;
    Tree *current;
    initP(&P);
    push(&P, root);

    if (root == NULL)
    {
        return -1;
    }
    else
    {
        while (!isEmpty(P))
        {
            tam = 0;
            levelAt = 1;
            while (tam < levelAt)
            {
                pop(&P, &current);
                if (current->esq != NULL)
                {
                    push(&P, current->esq);
                }
                if (current->dir != NULL)
                {
                    push(&P, current->dir);
                }
                tam++;
            }
            altura++;
        }
        return altura;
    }
}

int CalculaNivel(Tree *raiz, int info, int nivel)
{
    int nivelDireita, nivelEsquerda;
    if (raiz == NULL)
    {
        return -1;
    }
    else if (raiz->info == info)
    {
        return nivel;
    }
    else
    {
        nivelEsquerda = CalculaNivel(raiz->esq, info, nivel + 1);
        if (nivelEsquerda != -1)
        {
            return nivelEsquerda;
        }
        nivelDireita = CalculaNivel(raiz->dir, info, nivel + 1);
        return nivelDireita;
    }
}