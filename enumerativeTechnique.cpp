#include <iostream>

using namespace std;

void selection(int, int, int);
bool checking(int, int);

int maxA[101]; //Этот массив будет содержать наибольшее независимое множество, перый элемент хранит кол-во вершин
int combination[100]; //Этот массив будет содержать возможные комбинации
bool graph[100][100]; //Матрица смежности графа

int main()
{
	for (int i=0; i<100; i++)
	{
		maxA[i]=-1;               
		combination[i]=-1;          //обнуляем массивы (0 может указывать на вершину с индексом 0, -1 точно не
	}                            // укажет ни на одну вершину
	
	
	int vertex;//Кол-во вершин графа
	
	cout<<"Enter number of vertexes: ";//Вводим кол-во вершин
	cin>>vertex;
	for (int i=0, neg/*сосед*/; i<vertex; )
	{
		cout<<"Enter neighbors of "<<i<<" vertex (or -1 to go to next vertex): ";
		cin>>neg;
		if ((neg<0) or (neg>=vertex) or (neg==i))
		{
			i++;            //Переход к следущей вершине, если вводим <0 или больше, чем кол-во вершин, или есть петля
			continue;
		}
		graph[i][neg]=1;          //вводим соседей
		graph[neg][i]=1;         //вершины i
	}
	
	//Вывод таблицы смежности графа
	for (int i=0; i<vertex; i++)
	{
		if (!i)
			cout<<" ";               //Вывод списка столбцов графа
		cout<<" "<<i;
	}
	cout<<endl;
	for (int i=0; i<vertex; i++)
	{
		for (int j=0; j<vertex; j++)
		{
			if (!j)
			{
				cout<<i<<" ";              //Вывод списка строк графа
			}
			cout<<graph[i][j]<<" ";         //Вывод отношении между вершинами графа
		}
		cout<<endl;
	}
	
	selection (0, 0, vertex); //вызов функции перебора
	cout<<endl;
	for (int i=0; i<maxA[0]; i++)
	{
		cout<<maxA[i+1]<<" ";        //Вывод массива с наибольшим максимально независимым множеством
	}
	system("Pause>NULL");  //Пауза перед выходом из цикла
	return 0;		
}

bool checking(int index, int dimension)        //Функция проверяет, есть ли соседи
{
	for (int i=0; i<dimension; i++) //Пробег по занятым клеткам массива ombination
	{
		if ((graph[combination[i]][index]) or index==combination[i])     //Если связь существует, значит вершина не может быть добавлена к множеству
			return 0;
	}
	return 1;
}

void selection(int index, int anotherIndex, int dimension)
{
	if (anotherIndex==dimension)  //если обошли все вершины, то проверяем комбинацию с меющимся максимальным множеством
	{
		if (maxA[0]<index)     // Проверяем с имеющимся наибольшим максимальным независимым множеством (первый элемент содержит кол-во элементов в множестве)
		{
			maxA[0]=index;      //Если новая комбинация имеет большее кол-во элементов, то новый первый элемент max имеет кол-во вершин комбинации
			for (int i=0; i<index; i++)
			{
				maxA[i+1]=combination[i];             //Присваиваем max вершины комбинации
			}
		}
		return;                                        //Выход с рекурсии
	}
	for (int i=anotherIndex; i<dimension; i++)         //Если не дошли до конца, пробегаем по вершинам графа с позиции, где остановились на пршлом уровне
	{
		if (checking(i, index))                        //Если вершина не смежна с любой другой из комбинации, то проводим следующие махинации
		{
			combination[index]=i;                      //Присваиваем эту вершину в комбинацию
			selection(index+1, i+1, dimension);        //Переходим на следующий уровень, увеличивая на 1 размер комбинации и смещаем на 1 текущую позицию
	//		index--;
			
		}	
	}	
	if (maxA[0]<index)                       //Если ни одна вершина не подошла или вышли с рекурсии, идет снава проверка с имеющимся наибольшим независимым множеством
		{
			maxA[0]=index;                 //Если новая комбинация имеет большее кол-во элементов, то новый первый элемент max имеет кол-во вершин комбинации
			for (int i=0; i<index; i++)
			{
				maxA[i+1]=combination[i];//Присваиваем max вершины комбинации
			}
		}
		return; //выход с функции
}
