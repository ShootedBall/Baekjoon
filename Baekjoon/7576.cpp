#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

#define FLOWER 1
#define TOMATO 0
#define NOT -1
queue< pair<int, int> > next_queue;

bool Flowering(int graph[][1000], pair<int, int> point, int N, int M)
{
	bool check = false;

	/*���� �� �Ʒ� ������ ������ �˻�, �˻��ؼ� ���� FLOWER��Ų �丶���� ��ǥ�� next_queue�� ����*/
	if (point.first + 1 >= 0 && point.second >= 0 && point.first + 1 < M && point.second < N && graph[point.first + 1][point.second] == TOMATO)
	{
		graph[point.first + 1][point.second] = FLOWER;
		next_queue.push(make_pair(point.first + 1, point.second));
		check = true;
	}

	if (point.first - 1 >= 0 && point.second >= 0 && point.first - 1 < M && point.second < N && graph[point.first - 1][point.second] == TOMATO)
	{
		graph[point.first - 1][point.second] = FLOWER;
		next_queue.push(make_pair(point.first - 1, point.second));
		check = true;
	}

	if (point.first >= 0 && point.second + 1 >= 0 && point.first < M && point.second + 1 < N && graph[point.first][point.second + 1] == TOMATO)
	{
		graph[point.first][point.second + 1] = FLOWER;
		next_queue.push(make_pair(point.first, point.second + 1));
		check = true;
	}

	if (point.first >= 0 && point.second - 1 >= 0 && point.first < M && point.second - 1 < N && graph[point.first][point.second - 1] == TOMATO)
	{
		graph[point.first][point.second - 1] = FLOWER;
		next_queue.push(make_pair(point.first, point.second - 1));
		check = true;
	}

	return check; //�ϳ��� FLOWER �������� true����ȯ
}

int Tomato(int graph[][1000], int N, int M)
{
	queue< pair<int, int> > tomato_queue;
	bool check = false;

	//ó�� �����Ҷ� FLOWER�� �丶�並 ã�Ƽ� �丶�� ť�� ���� ����
	if (next_queue.empty())
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
			{
				if (graph[i][j] == FLOWER)
					tomato_queue.push(make_pair(i, j));
			}
	//1ȸ ���� �����ϰ� ���� ���� FLOWER �丶�信 ���� ���� �߰��� FLOWER �丶�丸 ť�鸸 �̿���(next_queue)
	else
		tomato_queue = next_queue;

	//next_queue ��Ȱ���� ���� ���� pop ������
	while (!next_queue.empty())
		next_queue.pop();

	while (!tomato_queue.empty())
	{
		pair<int, int> point = tomato_queue.front();
		tomato_queue.pop();
		check = Flowering(graph, point, N, M) || check;//�ֺ��� �ִ� TOMATO�� FLOWER ��Ű�� �̹� ���� FLOWER ������ 0�� ��ȯ
	}

	return check;
}

int main()
{
	int N, M;
	int graph[1000][1000] = { 0 };
	int count = 0;

	scanf("%d", &N);
	scanf("%d", &M);

	//INPUT
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			int temp;
			scanf("%d", &temp);
			graph[i][j] = temp;
		}

	//FLOWER
	while (Tomato(graph, N, M))
		count++;

	//���� FLOWER ��ų�����°� �־����� -1 ��ȯ
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (graph[i][j] == 0)
				count = -1;

	printf("%d", count);
	return 0;
}