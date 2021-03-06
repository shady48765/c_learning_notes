/*
3.   选小寿星
【问题描述】 五年级一班有一个传统，全班一起庆祝当月过生日的同学。有m名学生都是11月份过生日，
班主任决定挑一名学生作为寿星代表切蛋糕。班主任将过生日的m名学 生随机围成一个圈，从1到m进行编号。
随机挑一个数字n（1<=n<=9），从第一个同学开始连续报数，报数到n的同学就出局，然后从下一位 同学重新开始报数，
一直到剩下最后一名同学。由于女生少，班主任决定每个女生有2次机会，也就是说，每名女生第2次数到n时才出局。
例如，m=3,其中有1名女生，编号顺序为1,2,3，分别是男，女，男，n=2。第一轮报数，报到的是2号女生，暂不出局
（注：女生有2次机会）。第二轮报数， 3号男生报1，1号男生报2出局。第三轮报数，2号女生报1，3号男生报2出局，最后留下2号女生。 
有m=5，其中2名女生，编号顺序为1,2,3,4，5，分别为男，男，女，女，男。n=3。挑选后的结果是5号，男生。（注：女生有2次机会）  
输入：第一行输入数字为m，表示有m个人，m<20; 第二行是m个整数，1代表男生，0代表女生。 第三行是n，表示n是出局数字。
（注意：女生有2次机会）
输出：留下学生的序号。
【样例输入】
5
1 1 0 0 1
3
【样例输出】
5
*/
#include<iostream>
#include<deque>
using namespace std;
int main(){
    int m;              //m表示有m个人
    cin>>m;
    deque<int> q;       //男女
    deque<int> l;       //序号，之间会同步（略麻烦）
    int n;              //n是出局数字
    int t, tl;              //临时变量
    for(int i=1;i<=m;i++){
        cin>>t;
        t++;
        q.push_back(t);      //1表示男生1次机会，2表示女生2次机会。
        l.push_back(i);
    }
    cin>>n;
    while(!q.empty()){
        for(int i=1;i<n;i++){
            q.push_back(q.front());
            l.push_back(l.front());
            q.pop_front();
            l.pop_front();
            //移到队尾
        }
        if(q.front()==2){
            int z=q.front();
            q.pop_front();
            q.push_front(z-1);   //2次机会变1次
        }else{
            t=q.front();         //这里可能有点多余但我不想改
            tl=l.front();
            q.pop_front();
            l.pop_front();           //没机会了
        }
    }
    cout<<endl<<tl;
    return 0;
}