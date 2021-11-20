#include <iostream>

using namespace std;

void selection(int, int, int);
bool checking(int, int);

int maxA[101]; //���� ������ ����� ��������� ���������� ����������� ���������, ����� ������� ������ ���-�� ������
int combination[100]; //���� ������ ����� ��������� ��������� ����������
bool graph[100][100]; //������� ��������� �����

int main()
{
	for (int i=0; i<100; i++)
	{
		maxA[i]=-1;               
		combination[i]=-1;          //�������� ������� (0 ����� ��������� �� ������� � �������� 0, -1 ����� ��
	}                            // ������ �� �� ���� �������
	
	
	int vertex;//���-�� ������ �����
	
	cout<<"Enter number of vertexes: ";//������ ���-�� ������
	cin>>vertex;
	for (int i=0, neg/*�����*/; i<vertex; )
	{
		cout<<"Enter neighbors of "<<i<<" vertex (or -1 to go to next vertex): ";
		cin>>neg;
		if ((neg<0) or (neg>=vertex) or (neg==i))
		{
			i++;            //������� � �������� �������, ���� ������ <0 ��� ������, ��� ���-�� ������, ��� ���� �����
			continue;
		}
		graph[i][neg]=1;          //������ �������
		graph[neg][i]=1;         //������� i
	}
	
	//����� ������� ��������� �����
	for (int i=0; i<vertex; i++)
	{
		if (!i)
			cout<<" ";               //����� ������ �������� �����
		cout<<" "<<i;
	}
	cout<<endl;
	for (int i=0; i<vertex; i++)
	{
		for (int j=0; j<vertex; j++)
		{
			if (!j)
			{
				cout<<i<<" ";              //����� ������ ����� �����
			}
			cout<<graph[i][j]<<" ";         //����� ��������� ����� ��������� �����
		}
		cout<<endl;
	}
	
	selection (0, 0, vertex); //����� ������� ��������
	cout<<endl;
	for (int i=0; i<maxA[0]; i++)
	{
		cout<<maxA[i+1]<<" ";        //����� ������� � ���������� ����������� ����������� ����������
	}
	system("Pause>NULL");  //����� ����� ������� �� �����
	return 0;		
}

bool checking(int index, int dimension)        //������� ���������, ���� �� ������
{
	for (int i=0; i<dimension; i++) //������ �� ������� ������� ������� ombination
	{
		if ((graph[combination[i]][index]) or index==combination[i])     //���� ����� ����������, ������ ������� �� ����� ���� ��������� � ���������
			return 0;
	}
	return 1;
}

void selection(int index, int anotherIndex, int dimension)
{
	if (anotherIndex==dimension)  //���� ������ ��� �������, �� ��������� ���������� � �������� ������������ ����������
	{
		if (maxA[0]<index)     // ��������� � ��������� ���������� ������������ ����������� ���������� (������ ������� �������� ���-�� ��������� � ���������)
		{
			maxA[0]=index;      //���� ����� ���������� ����� ������� ���-�� ���������, �� ����� ������ ������� max ����� ���-�� ������ ����������
			for (int i=0; i<index; i++)
			{
				maxA[i+1]=combination[i];             //����������� max ������� ����������
			}
		}
		return;                                        //����� � ��������
	}
	for (int i=anotherIndex; i<dimension; i++)         //���� �� ����� �� �����, ��������� �� �������� ����� � �������, ��� ������������ �� ������ ������
	{
		if (checking(i, index))                        //���� ������� �� ������ � ����� ������ �� ����������, �� �������� ��������� ���������
		{
			combination[index]=i;                      //����������� ��� ������� � ����������
			selection(index+1, i+1, dimension);        //��������� �� ��������� �������, ���������� �� 1 ������ ���������� � ������� �� 1 ������� �������
	//		index--;
			
		}	
	}	
	if (maxA[0]<index)                       //���� �� ���� ������� �� ������� ��� ����� � ��������, ���� ����� �������� � ��������� ���������� ����������� ����������
		{
			maxA[0]=index;                 //���� ����� ���������� ����� ������� ���-�� ���������, �� ����� ������ ������� max ����� ���-�� ������ ����������
			for (int i=0; i<index; i++)
			{
				maxA[i+1]=combination[i];//����������� max ������� ����������
			}
		}
		return; //����� � �������
}
