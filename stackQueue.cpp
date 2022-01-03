#include <iostream>
#include <stdlib.h>

using namespace std;

class stack
{
    int e[100];
    int top, i, maxsize;

    public:
    void getmax (int max);
    stack()
    {
        top=0;
    }
    void push(int n);
    int pop();
    void show();
    void cloneStack(stack,stack,int max);
int stackEmpty()
  {
      if(top == 0)
        return 1;
      else
        return 0;
  }

  int stackFull()
  {
      if(top == maxsize)
        return 1;
      else
        return 0;
  }
  int getsize()
  {
      return maxsize;
  }
};

void stack::getmax (int max)
{
maxsize=max;
}

void stack::push(int n)
{
    if(stackFull())
    {
        cout<<"Stack overflow..."<<endl;
    }

    else
        e[top++]=n;
}

int stack::pop()
{
    if(stackEmpty())
    {
        cout<<"Stack underflow..."<<endl;
    }

    else
    return e[--top];
 }


 void stack :: show()
 {
    cout<<endl;
    for(i=0; i<top; i++)
    cout<<" "<<e[i];
 }

void cloneStack(stack a, stack b,int max)
{
    stack c;
    system("cls");
    cout<<"Stack A:"<<endl;
    a.show();
    for(int i=0; i<max; i++)
    {
        c.push(a.pop());
    }
    for(int i=0; i<max; i++)
    {
        b.push(c.pop());
    }
    cout<<endl<<endl<<endl;
    cout<<"Stack B:"<<endl;
    b.show();
}

int equalStacks (stack a, stack b)
{
    int equal=1;
    int Top1, Top2;
    while (!a.stackEmpty() && (!b.stackEmpty() && (equal)))
{
        Top1 = a.pop();
        Top2 = b.pop();
        if (Top1 != Top2)
            equal = 0;
    }

    if ((a.stackEmpty() && !b.stackEmpty()) || ((!a.stackEmpty()) && b.stackEmpty()) || a.getsize()!=b.getsize())
        equal = 0;

return equal;
}

class queue
{
int a[100];
int head,tail,max,size,count=0;
public:
void create(int size);
queue()
 {
 head=0;
 tail=0;
 }

int queueEmpty()
    {
        if(count==0)
            return 1;
        else
            return 0;
    }
int queueFull()
{
if(count==max)
            return 1;
        else
            return 0;
}
void insertItem(int Item,int n);
void enqueue(int n);
void dequeue();
void display();
int Qcount();
};

void queue::create(int size)
{
    max=size;
    head=-1;
    tail=-1;
    for(int i=0;i<max;i++)
        a[i]=NULL;
}
void queue::enqueue(int n)
{
if (queueEmpty())
    {
        head=0;
        tail=0;

    }
else
        tail=(tail+1)%max;
        a[tail]=n;
        count++;
}

void queue::dequeue()
{
    int x;
    if(queueEmpty())
        cout<<"Queue Underflow. Enqueue First\n";
    else
    {
        a[head]=NULL;
        head=(head+1)%max;
        count--;
    }
}

int queue::Qcount()
{
    return count;
}
void queue::insertItem(int Item,int n)
{
    int i,cnt;
    if(queueFull())
        cout<<"Queue Overflow. Dequeue First.\n";
    else
    {
        cnt=Qcount();
        if(n>=cnt)
            enqueue(Item);

        else
        {
            for(i=0;i<n;i++)
        enqueue(Item);
        }
    }

}

void queue::display()
{
cout<<"The Queue contains:"<<endl;
for(int i=0; i<max; i++)
{
        if(a[i]==NULL)
            cout<<" ";
        else

            cout<<a[i]<<" ";
}
}

 int main()
 {

    int n,choice,y,x;
    char z;
    cout<<"[1]equalStack Function"<<endl<<"[2]cloneStack Function"<<endl<<"[3]insertItem Function"<<endl<<"Choose:"; cin>>x;
    system("cls");
    switch (x)
    {
case 1:
    {
    stack first, second;
    back:
    cout<<"[A]Stack"<<endl<<"[B]Stack"<<endl<<"[C]Determine if both are equal"<<endl<<"Choose:";
    cin>>z;
    if (z=='A' || z=='a')
    {
        cout<<"Stack A:"<<endl<<"Enter size: "; cin>>n;
        first.getmax(n);
        system("cls");
        do{
        cout<<endl<<"Stack A:"<<endl<<"[1]Push"<<endl<<"[2]Pop"<<endl<<"[3]Go back"<<endl; cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter number:"<<endl;
                cin>>y;
                first.push(y);
                first.show();
            }
            break;

            case 2:
            {
                first.pop();
                first.show();
            }
            break;

            case 3:
                {
                system("cls");
                goto back;
                }
            break;

            default:
                cout<<"Your choice is out of range."<<endl;
                cout<<"Please try it again."<<endl;
            }
            } while(choice!=3);
    }
    else if (z=='B' || z=='b')
    {
        cout<<"Stack B:"<<endl<<"Enter size: "; cin>>n;
        second.getmax(n);
        system("cls");
        do{
        cout<<endl<<"Stack B:"<<endl<<"[1]Push"<<endl<<"[2]Pop"<<endl<<"[3]Go back"<<endl; cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter number:"<<endl;
                cin>>y;
                second.push(y);
                second.show();
            }
            break;

            case 2:
            {
                second.pop();
                second.show();
            }
            break;

            case 3:
                {
                system("cls");
                goto back;
                }
            break;

            default:
                cout<<"Your choice is out of range."<<endl;
                cout<<"Please try it again."<<endl;
            }
            } while(choice!=3);
    }

    else if (z=='C' || z=='c')
    {
        cout<<"Stack A: "<<endl;
                first.show();
                cout<<endl;
                cout<<endl;
                cout<<"Stack B: "<<endl;
                second.show();
                cout<<endl;
                cout<<endl;
    if(equalStacks(first,second))
                    cout<<"Stacks are equal"<<endl;
                else
                    cout<<"The Stacks are not equal"<<endl;

}
    }
break;
case 2:
    {
    stack first, second;
    cout<<"Stack A:"<<endl<<"Enter size: "; cin>>n;
        first.getmax(n);
        system("cls");
        do{
        error:
        cout<<endl<<"Stack A:"<<endl<<"[1]Push"<<endl<<"[2]Pop"<<endl<<"[3]Clone"<<endl; cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter number:"<<endl;
                cin>>y;
                first.push(y);
                first.show();
            }
            break;

            case 2:
            {
                first.pop();
                first.show();
            }
            break;

            case 3:
                {
                if(first.stackFull())
                    cloneStack(first,second,n);
                else
                {
                    cout<<"Cannot clone stack. Please push the remaining stack.";
                    goto error;
                }
                }
            break;

            default:
                cout<<"Your choice is out of range."<<endl;
                cout<<"Please try it again."<<endl;
            }
            } while(choice!=3);
    }
    break;
    case 3:
        {
        queue q;
        cout<<"Enter Queue Size: ";
        cin>>n;
        q.create(n);
        do
        {
            cout<<"\nEnter choice:"<<endl;
            cout<<"1. Enqueue"<<endl;
            cout<<"2. Dequeue"<<endl;
            cout<<"3. Exit"<<endl;
            cin>>choice;

        switch(choice)
            {
            case 1:
            {
            cout<<"Enter number:"<<endl;
            cin>>y;
            q.insertItem(y,n);
            q.display();
            }
            break;
            case 2:
            q.dequeue();
            q.display();
            break;

            case 3:
            cout<<"The program is now exited."<<endl;
            break;

            default:
            cout<<"Your choice is out of range."<<endl;
            cout<<"Please try it again."<<endl;
            break;
            }
            }
            while(choice!=3);
        }
    }
 return 0;
 }
