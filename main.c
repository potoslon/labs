#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


char *get_str() {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }

    return res;
}

char *rm_spaces(const char *s) {
	int len = 0;
	int i = 0;
	char *res = calloc(strlen(s) + 1, sizeof(char));
	while (s[i] == ' ') { ++i; }
	while (s[i]) {
		int j = i;
		while (s[j] && s[j] != ' ') { ++j; }
		strncat(res, &s[i], j - i);
		len += j - i;
		i = j;
		while (s[j] == ' ') { ++j; }
		if (s[j]) {
			strncat(res, " ", 1);
			len++;
		}
		i = j;
	}
	res = realloc(res, len + 1);
	res[len] = '\0';
	return res;
}

Stack * stack_form(int* n, int o, int* m)
{
    int i = 0, j = 0, k = 0;
    char *a;
    char *t;
    char *c;
    Stack *l;
    l = stack_new();
    printf("Please enter the string\n");
    scanf("%*c");
    t = get_str();//printf("t = %s\n", t);
    if (t == NULL){
        *n = -1;
        return l;
    }
    a = rm_spaces(t);
    free(t);
    if (!*a){
        *n = -2;
        free(a);
        return l;
    }
    while ( *(a + j) ) {
        while(*(a + i) && *(a + i) != ' '){  //printf("%s\n", a);
            i = i + 1;
        }
        c = calloc(o+1, sizeof(char));
        memcpy(c, a + j, i - j);   printf(",%s,\n", c);
        k = stack_push(l, c);
        if(k == -1){
            printf("Overflov\n");
            free(a);
            free(c);
            *n = -2;
            return l;
        }
        *m = *m + 1;
        if ( *(a + i) ){
            i = i + 1;
        }
        j = i;
    }
    *n = 1;
    stack_print(l);
    free(a);
    return l;
}

char* rebuild(Stack *l, int o, int m) {
    int n = 0, k, r, i, flag = 0;
    char *res = NULL;
    char *buf = NULL;
    Stack *dop;
    dop = stack_new();
    char *s = NULL;
    char *op1 = NULL;
    char *op2 = NULL;
    char *buf1 = NULL;
    const char *Br1 = ")";
    for(i = 0; i < o; i++) {printf("\n1\n");

       n = stack_pop(l, &s);
       if (*s) {
           if (*s == '+' || *s == '-' || *s == '*' || *s == '/'){
               k = stack_pop(dop, &op1);
               r = stack_pop(dop, &op2);
               if (k == -1){
                  printf("Uncorrect input 1\n");
                  stack_delete(dop);
                  free(s);
                  return NULL;
               }
               if (r == -1){
                  printf("Uncorrect input 2\n");
                  stack_delete(dop);
                  free(op1);
                  free(s);
                  return NULL;
               }
               buf1 = calloc(o * m, sizeof(char));
               buf = calloc(o * m, sizeof(char));
               buf[0] = '(';
               op2 = strcat(op2, Br1);
               buf1 = memcpy(buf1, s, strlen(s));
               buf1 = strcat(buf1, op2);
               buf = strcat(buf, op1);
               buf = strcat(buf, buf1);
               stack_push(dop, buf);
               free(op1);
               free(op2);
               free(s);
               free(buf1);
               flag = 1;
           }
           else if (n != -1) {
               int r = stack_push(dop, s);
           }
       }
    }
    if (flag == 0){
        stack_delete(dop);
        printf("Uncorrect input 3\n");
        return NULL;
    }
    res = calloc(strlen(buf) + 1, 1);
    res = memcpy(res, buf, strlen(buf));
    stack_delete(dop);
    return res;
}


int main() {
    Stack *l = NULL;
    int n = 0, o, e, m = 0;
    char *res = NULL;
    do{
        printf("Please enter max size of element\n");
        e = scanf ("%d", &o);
        if (e < 0) {
           return 1;
        }
        else if(e == 0){
           printf("You are wrong, try again\n");
           scanf("%*c");
        }
        else if (e > 0){
            o = o + 1;
            l = stack_form(&n, o, &m);
            if (n >= 0) {
               res = rebuild(l, m, o);
               if (res){
                  printf("result: %s\n", res);
                  free(res);
               }
            }
            stack_delete(l);
            m = 0;
        }
    } while(e >= 0 && n != -1);
    return 0;
}
