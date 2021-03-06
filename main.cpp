#include<iostream>
#include<conio.h>

using namespace std;

struct myLst;
typedef myLst* pLst;
struct myLst
{
	pLst next;
	int R;
	union
	{
		pLst level;
		char atom;
	};
};

pLst Init()
{
	pLst lst = NULL;
	return lst;
}

bool IsEmpty(pLst lst)
{
	return(lst == NULL);
}

void lstScan(pLst &lst)
{
	char c;
	c = _getch();
	cout << c;
	if (c != '\r')
	{
		if (c == '(')
		{
			lst = new myLst;
			lst->R = 0;
			lstScan(lst->level);
			lstScan(lst->next);
		}
		else if (((c >= 'a') && (c <= 'z')) || (c == '+') || (c == '-') || (c == '/') || (c == '*'))
		{
			lst = new myLst;
			lst->R = 1;
			lst->atom = c;
			lstScan(lst->next);
		}
		else if (c == ')')
			lst = NULL;
	}
}

void lstPrint(pLst lst)
{
	pLst lstTmp;
	if (lst->R == 1)
		cout << lst->atom;
	else
	{
		cout << '(';
		lstTmp = lst->level;
		while (lstTmp != NULL)
		{
			lstPrint(lstTmp);
			lstTmp = lstTmp->next;
		}
		cout << ')';
	}
}

void main()
{
	pLst lst = Init();
	lstScan(lst);
	cout << endl;
	lstPrint(lst);
	cout << endl;
	system("pause");
}
