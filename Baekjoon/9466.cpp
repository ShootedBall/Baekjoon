#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>//For using std::find in gcc
using namespace std;

#define SEARCHING 0
#define SEARCHED 2

int main()
{
	int T;
	vector<int> count;
	scanf("%d", &T);

	//�׽�Ʈ ���̽� T �ݺ�
	for (int i = 0; i < T; i++)
	{
		//Define
		vector<int> status;
		vector<int> buf;
		map<int, int> pair;
		int searched = 0;
		int connets = 0;

		//Input
		int n;
		scanf("%d", &n);
		status.resize(n + 1);
		status.assign(status.size(), SEARCHING);
		status[0] = -1;

		for (int i = 1; i <= n; i++)
		{
			int temp;
			scanf("%d", &temp);
			pair.insert(make_pair(i, temp));
		}

		int start = -1;
		int temp;

		//���� Ž���������� start ���� ã��
		for (int i=1; searched !=n; i++)
		{

			if (status[i] == SEARCHING)
			{
				start = i;
				temp = i;

				//����� 1��Ʈ�� ã��
				for (int i = 1; i <= (n - connets) + 1; i++)
				{
					//¦����
					if (status[temp] == SEARCHING)
					{
						status[temp] = SEARCHED; //����Ϸ��ϰ�
						searched++; // searched ���� ������Ų����
						buf.push_back(temp); //������� �����Ǵ� �����ĺ����� buf�� �־��
						temp = (pair[temp]); // ���� ¦ �˻�
					}

					//6���� ����� Ž�� �׷��� �������� ��� Ż��
					else if (status[temp] == SEARCHED)
					{
						//������� �߰��ϸ�
						vector<int>::iterator itr = find(buf.begin(), buf.end(), temp);
						if (itr != buf.end())
							connets += buf.size() - (itr - buf.begin()); // ����� ������������ ���������� ����� ������ ����
						break;
					}
				}
				buf.clear();

			}
		}

		count.push_back(n - connets);
	}

	for (int i = 0; i < count.size(); i++)
		printf("%d\n", count[i]);

	return 0;
}