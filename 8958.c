#include<stdio.h>

int main(){
    char arr[81]; // ���� ���
    int Tcase; // �׽�Ʈ ���̽�
    int score = 0; // ��������
    int scoretemp = 0; // ����
    int idx = 0; // ���ڿ� �ε���, �ι��� �Ǻ��� ����

    scanf("%d", &Tcase);

    for (int i = 0; i < Tcase; i++) {
        scanf("%s", arr);
        score = 0; // ���� ���� ���� �ʱ�ȭ
        scoretemp = 0;
        idx = 0;
        while (arr[idx] != '\0') {
            if (arr[idx] == 'O') {
                scoretemp += 1;
                score += scoretemp;
            } else {
                scoretemp = 0;
            }
            idx++;
        }
        printf("%d\n", score);
        
    }
    
    return 0;
}