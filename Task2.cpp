#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>

typedef struct link {
	int id;
	struct link* next;
} list;
list *L;

void push(list* &L, int add)
{
    list* tmp = new list;
    tmp->id = add;
    tmp->next = L;
    L = tmp;
};
void L_print(list* L) {
    std::cout << "List:[ ";
    for (;;) {
		std::cout << L->id<<" ";
        if (L->next == NULL) break;
        L = L->next;
    }
	std::cout << " ]" << std::endl;
}

void add_before(list* &L, int add, int where)
{
    list* tmp = L, * p;
    p = new list;
    p->id = add;
    if (tmp->id == where)
    {
        p->next = L;
        L = p;
    }
    else
    {
        while (tmp->next != NULL && tmp->next->id != where)tmp = tmp->next;
        if (tmp->next != NULL)
        {
            p->next = tmp->next;
            tmp->next = p;
        }
    }

}
void add_after(list* &L, int add, int where)
{
    list* tmp = L, * p;
    p = new list;
    p->id = add;
    while (tmp != NULL && tmp->id != where)tmp = tmp->next;
    if (tmp != NULL)
    {
        p->next = tmp->next;
        tmp->next = p;
    }

}
void push_tail(link* &list, int add)
{
	link* tmp = L, * p;
    p = new link;
    p->id = add;
    while (tmp->next != NULL)tmp = tmp->next;
    tmp->next = p;
    p->next = NULL;
}
int pop(list* &L)
{
    list* tmp = L;
    L = L->next;
    int x = tmp->id;
    delete(tmp);
    return x;
}
int pop_tail(list* &L)
{
    int x;
    list* tmp = L;
    if (L->next == NULL)
    {
        x = L->id;
        delete(L);
        L = NULL;
        return x;
    }
    else
    {
        while (tmp->next->next != NULL)tmp = tmp->next;
        x = L->id;
        delete(tmp->next);
        tmp->next = NULL;
        return x;
    }

}
int pop_concrete(list* &L, int c)
{
    list* tmp = L, * p;
    if (tmp->id == c)
    {
        L = L->next;
        delete(tmp);
        return c;
    }
    else
    {
        while (tmp->next != NULL && tmp->next->id != c)tmp = tmp->next;
        if (tmp->next != NULL)
        {
            p = tmp->next;
            tmp->next = tmp->next->next;
            delete(p);
            return c;
        }
        else
            return -1;
    }
}

void Indiv(list* &L) {
	link* cur = L;
	std::unordered_set<int> numbers = {};
	while (cur->next != nullptr) {
		if (numbers.contains(cur->next->id)) {
			cur->next = cur->next->next;
		}
		else {
			numbers.insert(cur->next->id);
			cur = cur->next;
		}
	}
}

int main()
{
    int n , m,in;
    push(L, 0);
    for (int i = 0; i <= 10; i++) {
           push_tail(L, i*10+2);
    }
    L_print(L);
    int action;
    do {
        printf("\n0: Exit\n"
            "1: Insert n at the begin\n"
            "2: Insert n at the end\n"
            "3: Insert n before the m elem.\n"
            "4: Delete first element\n"
            "5: Delete element n\n"
            "6: Individual\n"
            "7: Insert n after the m elem.\n");
        std::cin >> action;
        if (action == 0) break;
        if (action == 1) {
			std::cin >> n;
            push(L, n);
            L_print(L);
            continue;
        }
        if (action == 2) {
			std::cin >> n;
            push_tail(L, n);
            L_print(L);
            continue;
        }
        if (action == 3) {
			std::cin >> n;
			std::cin >> m;
           add_before(L, n, m);
            L_print(L);
            continue;
        }
        if (action == 4) {
            pop(L);
            L_print(L);
            continue;
        }
        if (action == 5) {
			std::cin >> m;
            pop_concrete(L, m);
            L_print(L);
            continue;
        }
        }
        if (action == 6) {
			std::cin >> n;
			std::cin >> m;
            add_after(L, n, m);
            L_print(L);
            continue;
        }
        if (action == 7) {
            Indiv(L);
            L_print(L);
            continue;
        }
        

    } while (1);
    return 0;
}