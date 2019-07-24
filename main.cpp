#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;


void printRs(vector<vector<string>> &rs)
{
    for(auto vec:rs)
    {
        for(string s: vec)
        {
            //cout<<s<<endl;
            for(auto a:s)
            {
                cout<<a<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

void printsRs(vector<int> ars, int N)
{
    system("clear");
    for(auto i: ars)
    {
        string line(N,'+');
        line[i]='Q';
        for(auto a:line)
        {
            cout<<a<<' ';
        }
        cout<<endl;
    }
    for(int u=ars.size();u<N;u++)
    {
        for(int i=0;i<N;i++)
        {
            cout<<"+ ";
        }
        cout<<endl;
    }
    usleep(700000);
    if(ars.size()==N)
    {
        cout<<"A GOOD ANSER!"<<endl;
        usleep(700000);
        cout<<"press any key to find another anser.";
        getchar();
    }

}


int absolute(int x)
{
    return x<0?-x:x;
}

bool isConfilct(int row1,int col1,int row2,int col2)
{

    int r1=absolute(row1-row2);
    int c1=absolute(col1-col2);


    if(row1==row2||col1==col2||(absolute(row1-row2)==absolute(col1-col2)))
    {
        return true;
    }
    else
        return false;
}

bool isGoodPos(vector<int> prs, int row,int col,int N )
{
    if(prs.size()>N) return false;
    for(int row1=0;row1<prs.size();row1++)
    {
        if(isConfilct(row1,prs[row1],row,col))
            return false;
    }
    return true;
}

void solution(int row, int N, vector<int> ars, vector<vector<int>> &rs)
{
    if(row>=N)
    {
        rs.push_back(ars);
        return;
    }

    for(int col=0;col<N;col++)
    {
        if(isGoodPos(ars,row,col,N))
        {
            ars.push_back(col);

            printsRs(ars,N);
            solution(row+1,N,ars,rs);
            //回溯
            ars.pop_back();
            printsRs(ars,N);
        }
    }
    return;
}





vector<vector<string> >  NqueenSolution(int N)
{
    vector<int> ars;
    vector<vector<int> > rs;
    solution(0,N,ars,rs);


    vector<vector<string> > frs;
    for(auto srs: rs)
    {
        vector<string> grahars;
        for(int i: srs)
        {
            string ssars(N,'+');
            ssars[i]='Q';
            grahars.push_back(ssars);
        }
        frs.push_back(grahars);
    }

    return frs;
}

int main() {


    int N=8;

    cout<<"input N:";
    cin>>N;

    vector<vector<string> > rs=NqueenSolution(N);


    cout<<"final anser:"<<endl;
    printRs(rs);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}