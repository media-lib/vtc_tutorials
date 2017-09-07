#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100

struct tnode {                        /* the tree node: */
 char *word;                          /* points to the text */
 int count;                           /* number of occurrences */
 struct tnode *left;                  /* left child */
 struct tnode *right;                 /* right child */
};

struct tnode *addtree(struct tnode *, char *);
struct tnode *talloc(void);
void treeprint(struct tnode *);
void ungetch(int);
int getword(char *, int);
int getch(void);

char buf[BUFSIZE];                    /* buffer for ungetch */
int bufp = 0;                         /* next free position in buf */

                          
int main(void) {                      /* word frequency count */
 struct tnode *root;
 char word[MAXWORD];

 root = NULL;
 while(getword(word, MAXWORD) != EOF)
  if(isalpha(word[0]))
    root = addtree(root, word);

 treeprint(root);
 exit(0);
}

                                      /* getword: get next word or character from input */
int getword(char *word, int lim) {
 int c, getch(void);
 void ungetch(int);
 char *w = word;

 while(isspace(c = getch()))
  ;
 if(c != EOF)
  *w++ = c;
 if(!isalpha(c)) {
  *w = '\0';
  return c;
 }
 for(; --lim > 0; w++)
  if(!isalnum(*w = getch())) {
   ungetch(*w);
   break;
  }
 *w = '\0';
 return word[0];
}

                                       /* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
 int cond;

 if(p == NULL) {                       /* a new word has arrived */
  p = talloc();                        /* make a new node */
  p->word = _strdup(w);
  p->count = 1;
  p->left = p->right = NULL;
 } else if((cond = strcmp(w, p->word)) == 0)
  p->count++;                          /* repeated word */
 else if(cond < 0)                     /* less than into left subtree */
  p->left = addtree(p->left, w);
 else                                  /* greater than into right subtree */
  p->right = addtree(p->right, w);

 return p;
}

                                       /* talloc: make a tnode */
struct tnode *talloc(void) {
 return(struct tnode *)malloc(sizeof(struct tnode));
}

                                       /* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
 if(p != NULL) {
  treeprint(p->left);
  printf("%4d %s\n", p->count, p->word);
  treeprint(p->right);
 }
}

int getch(void) {
 return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
 if(bufp >= BUFSIZE)
  printf("ungetch: too many characters\n");
 else
  buf[bufp++] = c;
}
