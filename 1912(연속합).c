//백준 1912번

/*배열을 A[i]로 두었을 떄 A[i]에서 끝나는 최대 연속 구간의 합은 
"항상 A[i]"거나 "A[i-1]을 오른쪽 끝으로 갖는 최대합"에 A[i]를 더한 것이다.


예를 들어보자.

배열이 [-7,-4,-3,6,3,-8,3,4] 이렇게 담겨져 있을떄
A[0]까지의 최대 연속 구간의 합은 A[0]그 자체이다. 
편의를 위해 배열 A[i]의 최대 연속 구간의 합을 Sum[i]로 표현하겠다.
Sum[0] = A[0]이다.
Sum[1]을 구해보자.
Sum[1]의 값은
"항상 A[i]이거나 A[i-1]을 오른쪽 끝으로 갖는 최대합에 A[i]를 더한 것" 이다.
Sum[1]값은 그러므로 -4 or (Sum[0] + A[1])이 된다.
-4와 -7-4를 비교해서 큰 값이 Sum[1]이 된다.
*/

#include <stdio.h>
int Max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int main(void){
   
    int n;
    scanf("%d",&n);
   
    int arr[100001];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
   
    int Sum[100001];
    Sum[0] = arr[0];
   
    for(int i = 0;i<n;i++){
        Sum[i] = Max(arr[i],Sum[i-1]+arr[i]);
    }
    int max = -1001;
   
    for(int i = 0;i<n;i++){
        if(Sum[i] > max){
            max = Sum[i];
        }
    }
    printf("%d",max);
}