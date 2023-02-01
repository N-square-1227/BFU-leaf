#include <iostream>
using namespace std;

typedef struct {
	char vex[50];//�����
	int matrix[50][50];//�ڽӾ���
	int vexnum, arcnum;//ͼ�ĵ�ǰ�����ͱ���
}AMGraph;
int path[50], pre[50];
char IndexVex(AMGraph amg, int u) 
{//�����򷵻�u�ڶ�����е��±꣬���򷵻�-1
	return amg.vex[u];
}

int GetPos(AMGraph amg, char v)
 {
	for (int i = 0; i < amg.vexnum; i++) 
	{
		if (v == amg.vex[i])//����Ķ���v��amg���ҵ�
			return i;
	}
	return -1;
}
int Create(AMGraph& amg,int vex,int edge)
 {//�����ڽӾ����ʾ��������������amg
	char v1, v2;
	int w;

	amg.vexnum = vex;//�ܶ�����
	amg.arcnum = edge;//�ܱ���
	for (int i = 0; i < amg.vexnum; ++i)
		cin >> amg.vex[i];
	for (int i = 0; i < amg.vexnum; ++i)//��ʼ���ڽӾ��󣬱ߵ����Ȩֵ����Ϊ����ֵ10000
		for (int j = 0; j < amg.vexnum; ++j)
			amg.matrix[i][j] = 10000;
	int i, j;
	for (int k = 0; k < amg.arcnum; ++k)
	 {//�����ڽӾ���
		cin >> v1 >> v2 >> w;//����һ���������Ķ��㼰Ȩֵ
		i = GetPos(amg, v1);
		j = GetPos(amg, v2);//ȷ��v1��v2��amg�е�λ�ã�������������±�
		amg.matrix[i][j] = w;//��<v1,v2>��Ȩֵ��Ϊw
		//amg.matrix[j][i] = amg.matrix[i][j];//��<v1,v2>�ĶԳƱ�<v2,v1>��ȨֵΪw
	}//for
	return 1;
}
/*
* �Ͻ�˹�����㷨��ʵ��
* �����ô�Ȩ���ڽӾ���matrix����ʾ��Ȩ������amg,amg.matrix[i][j]��ʾ��<vi,vj>�ϵ�Ȩֵ��
* ��<vi,vj>�����ڣ�����amg.matrix[i][j]Ϊ�����Դ��v0
* �㷨��ʵ��Ҫ�������¸��������ݽṹ
* ��һά����pre[i]:��¼��Դ��v0���յ�vi�Ƿ��ѱ�ȷ�����·�����ȣ�true��ʾȷ����false��ʾ��δȷ��
* �ڶ�ά����pre[i]:��¼��Դ��v0���յ�vi�ĵ�ǰ���·����vi��ֱ��ǰ��������š�
* ���ֵΪ:�����v0��vi�л�����pre[i]Ϊv0;����Ϊ-1
* ��һά����path[i]:��¼��Դ��v0���յ�vi�ĵ�ǰ���·����vi�ĵ�ǰ���·�����ȡ����ֵΪ:�����v0
* ��vi�л�����path[i]Ϊ���ϵ�Ȩֵ������Ϊ������
*/

void Find(AMGraph amg, char V)
 {//��Dijkstra�㷨��������amg��v0���㵽���ඥ������·��
	int nextvex, min;
	int visit[50];
	int pos = GetPos(amg, V);
	for (int i = 0; i < amg.vexnum; i++)
	{
		visit[i] = false;//visit��ʼΪ�ռ�
		path[i] = amg.matrix[pos][i];//��pos�������յ�����·�����ȳ�ʼ��Ϊ���ϵ�Ȩֵ
		if (path[i] < 10000) 
			pre[i] = pos;//���pos��i֮���л�����iǰ����Ϊpos
		else
			pre[i] = -1;//���pos��i֮���޻�����iǰ����Ϊ-1
	}
	visit[pos] = true;//��pos����visit
	path[pos] = 0;//Դ�㵽Դ��ľ���Ϊ0
	/*������������������ʼ����������ʼ��ѭ����ÿ�����pos��ĳ������v�����·������v�ӵ�visit������������������*/
	for (int i = 1; i < amg.vexnum; i++) 
	{//������amg.vexnum-1�����㣬���ν��м���
		min = 10000;
		for (int j = 0; j < amg.vexnum; ++j)
		 {
			if (!visit[j] && path[j] < min) 
			{
				nextvex = j;
			    min = path[j];//ѡ��һ����ǰ�����·�����յ�Ϊnextvex 
			}
		}
		visit[nextvex] = true;//��nextvex����visit
		for (int j = 0; j < amg.vexnum; j++) 
		{//���´�pos����������V-visit�����ж�������·������
			if (!visit[j] && (path[nextvex] + amg.matrix[nextvex][j] < path[j]))
			{
				path[j] = path[nextvex] + amg.matrix[nextvex][j];//����path[j]
				pre[j] = nextvex;//����j��ǰ��Ϊnextvex
			}
		}
	}
}

void Show(AMGraph amg, int v) 
{
	if (pre[v] == -1)
		return;
	else 
	{
		Show(amg, pre[v]);
		cout << IndexVex(amg, pre[v]) << " ";
	}
}

int main() {
	char city1, city2;//�������֣���㡢�յ�
	int a, b;//n�����У�m��·��
	while (cin >> a >> b && a && b)
	{
		AMGraph amg;
		Create(amg, a, b);
		cin >> city1>>city2;
		Find(amg, city1);
		cout << path[GetPos(amg, city2)] << endl;
		Show(amg, GetPos(amg, city2));
		cout << city2 << endl;
	}
	return 0;
}

