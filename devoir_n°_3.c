#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// first part of principal program.
    struct article
    {
        char code[20];
        char libeller[20];
        int prix_unitary;
        int quantity;
    } arts, stock[100];

    struct ligne_vente
    {
        struct article article_;
        int quantity_sell;
        float delivery;
    } vent;


    // int q;
    // printf("Please enter the total number of articles:");
    // scanf("%d", &q);

// typedef struct article arts;

// typedef struct line_vented vent;



// The second part of the program.




// The supplying

struct article record_one_article()
{
    struct article *a,x;
    a = &x;
    printf("Give the code of article: ");
    scanf("%s", a->code);      
    printf("\nGive the libeller: ");
    scanf("%s", a->libeller);
    printf("\nGive the prix unitary: ");
    scanf("%d", &a->prix_unitary);
    fflush(stdin);
    printf("\nGive the quantity: ");
    scanf("%d", &a->quantity);
    fflush(stdin);
    return x;
}


void record_articles(struct article t[100])
{
    int i = 0;
    printf("We go starting to supplying. ");
    while (i < 100) 
    {
        t[i] = record_one_article();
        if ((strcmp(t[i].code,"o") == 0) || strcmp(t[i].code,"O") == 0)
        {
            break;
        }
        else
            i++;
    }
}

// the sell method(process and functions)

struct article find_one_article(struct article a) 
{
    char *e,b[] = "O";
    e = b;
    int i;
    record_articles(stock);
    printf("We are starting to search in the list of articles. ");
    printf("\nGiven the code: ");
    scanf("%s", a.code);
    if ((strcmp(a.code,e) == 0))
    {
        printf("End of written. ");
        goto sortie_;
    }
    else
    {
        for(i = 0;i < 100; i++)
        {
            if (strlen(a.code) == strlen(stock[i].code) && strcmp(a.code,stock[i].code) == 0)
            {    
                goto sortie__;
            }
            if(i == 99)
            {
                printf("No such article");
                goto sortie;
            }
            sortie : break;
        }
    }
        sortie_ :  return (a);
        sortie__: return (stock[i]);
}


struct ligne_vente add_line_sell(struct ligne_vente e[100])
{
    char t = 'a';
    int i = 0;
    struct article y;
    y = find_one_article(e->article_);
    if (y.quantity != 0)
    {
        while ((t != 'Y') || (t != 'N') || (t != 'y') || (t != 'n'))
        {
            printf("\nConfirmed the add of article by (Y/N) in the bracket: ");
            scanf("%c", &t);
            if ((t == 'Y') || (t == 'y'))
            {
                e[i].article_ = y;
                i++;
                goto next;
            }
            else if ((t == 'N') || (t == 'n'))
            {
                break;
            }
            else
                printf("WARNING: Given the answer between 'Yes' or 'No', (Y/N).\n");
        }
    }
    next : return (e[i]);
}

void fill_bracket(struct ligne_vente v[100])
{
    int i = 0;
    struct ligne_vente x[100];
    while ((i >= 0) && (i < 100))
    {
        v[i] = add_line_sell(x);
        if ((v[i].article_.quantity == 0))
        {
            break;
        }
        i++;
    }
}


float calculate_amount_line(struct ligne_vente *m)
{
    float amount = 0;
    if ((m->article_.prix_unitary != 0))
    {
        m->delivery = 0.1;
        printf("Given the quantity: ");
        scanf("%d", &m->quantity_sell);
        amount = (m->article_.prix_unitary - m->delivery)*m->quantity_sell;
    }
    return (amount);
}


float calculate_total_amount(struct ligne_vente *M)
{
    int i = 0;
    float amount_;
    while(i < 100)
    {
        amount_ = calculate_amount_line(M+i);
        if ((amount_ != 0))
        {
            i++;
            goto done;
        }
        else
            break;
    }
    done :  return (amount_);
}


void show_line_sell(struct ligne_vente g)
{
    float q;
    q = calculate_amount_line(&g);
    if (q != 0)
    {
        printf("The libeller is %s, the unitary price is %d, the quantity is %d and the total amount see: %f\n",g.article_.libeller,g.article_.prix_unitary,g.quantity_sell,q);
    }
    else
        printf("Good bye!\n");
    
}


void show_all(struct ligne_vente G[100])
{
    int i = 0;
    float y = 0;
    while (i < 100)
    {
        show_line_sell(G[i]);
        y = calculate_total_amount(G+i);
        if (y == 0)
        {
            break;
        }
        y += calculate_total_amount(G+i);
        i++;
    }
    printf("We are charging for %f FCFA. ",y);
}


void destocker_un(struct article *stock, struct ligne_vente *v)
{
    int i;
    for ( i = 0; i < 100; i++)
    {
        stock[i].quantity = v[i].quantity_sell;
    }
    
}


void destocker_all(struct article stock[100], struct ligne_vente d[100])
{
    destocker_un(stock, d);    
}


int main()
{
    // void record_articles(struct article t[100]);
    // struct article find_one_article(struct article a[100]);
    // struct ligne_vente add_line_sell(struct ligne_vente e[100]);
    // void fill_bracket(struct ligne_vente v[100]);
    // struct ligne_vente calculate_amount_line(struct ligne_vente *m);
    // struct ligne_vente calculate_total_amount(struct ligne_vente *M);
    // void show_line_sell(struct ligne_vente g);
    // void show_all(struct ligne_vente G[100]);
    // void destocker_un(struct article *stock, struct ligne_vente *v);
    // void destocker_all(struct article stock[100], struct ligne_vente d[100]);
    // void fill_bracket(stock);
    // struct ligne_vente V[100];
        void record_articles(struct article stock[100]);
        struct article find_one_article(stock);
    return 0;
}