/*
 * Source: Dr. M Lehr
 */

#include "mArray.h"
#include <fstream>
#include <cmath>
using namespace std;

mArray::mArray(char *fn){
    ifstream in;
    in.open(fn);
    double rd,cd;
    in>>rd;
    in>>cd;
    Rows=static_cast<int>(rd);
    Cols=static_cast<int>(cd);
    Data=new double*[Rows];
    for(int r=0;r<Rows;r++){
        Data[r]=new double[Cols];
    }
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
                in>>Data[r][c];
        }
    }
    in.close();
}

mArray::mArray(int rd,int cd){
    Rows=rd;
    Cols=cd;
    Data=new double*[Rows];
    for(int r=0;r<Rows;r++){
        Data[r]=new double[Cols];
    }
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
            Data[r][c]=0.0;
        }
    }
}

mArray::mArray(const mArray &d){
    Rows=d.Rows;
    Cols=d.Cols;
    Data=new double*[Rows];
    for(int r=0;r<Rows;r++){
        Data[r]=new double[Cols];
    }
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
            Data[r][c]=d.Data[r][c];
        }
    }
}

mArray::mArray(bool z,const mArray &d,int rb,int re,int cb,int ce){
    if(z){
        Rows=re-rb+1;
        Cols=ce-cb+1;
        Data=new double*[Rows];
        for(int r=0;r<Rows;r++){
            Data[r]=new double[Cols];
        }
        for(int r=0;r<Rows;r++){
            for(int c=0;c<Cols;c++){
                Data[r][c]=d.Data[rb+r][cb+c];
            }
        }
    }else{
        Cols=re-rb+1;
        Rows=ce-cb+1;
        Data=new double*[Rows];
        for(int r=0;r<Rows;r++){
            Data[r]=new double[Cols];
        }
        for(int r=0;r<Rows;r++){
            for(int c=0;c<Cols;c++){
                Data[r][c]=d.Data[rb+c][cb+r];
            }
        }
    }
}

mArray::mArray(bool z,const mArray &d){
    int rb=0;
    int re=d.getRows()-1;
    int cb=0;
    int ce=d.getCols()-1;
    if(z){
        Rows=re-rb+1;
        Cols=ce-cb+1;
        Data=new double*[Rows];
        for(int r=0;r<Rows;r++){
            Data[r]=new double[Cols];
        }
        for(int r=0;r<Rows;r++){
            for(int c=0;c<Cols;c++){
                Data[r][c]=d.Data[rb+r][cb+c];
            }
        }
    }else{
        Cols=re-rb+1;
        Rows=ce-cb+1;
        Data=new double*[Rows];
        for(int r=0;r<Rows;r++){
            Data[r]=new double[Cols];
        }
        for(int r=0;r<Rows;r++){
            for(int c=0;c<Cols;c++){
                Data[r][c]=d.Data[rb+c][cb+r];
            }
        }
    }
}

mArray::~mArray(){
    for(int i=0;i<Rows;i++){
        delete []Data[i];
    }
    delete []Data;
}

mArray mArray::operator+(const mArray &right){
    mArray temp(Rows,Cols);
    int m=right.Cols;
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
            temp.Data[r][c]=Data[r][c]+right.Data[r][c%m];
        }
    }
    return temp;
}

mArray mArray::operator-(const mArray &right){
    mArray temp(Rows,Cols);
    int m=right.Cols;
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
            temp.Data[r][c]=Data[r][c]-right.Data[r][c%m];
        }
    }
    return temp;
}

mArray mArray::operator*(const mArray &right){
    mArray temp(Rows,right.Cols);
    for(int r=0;r<Rows;r++){
        for(int c=0;c<right.Cols;c++){
            for(int k=0;k<Cols;k++){
                    temp.Data[r][c]+=Data[r][k]*right.Data[k][c];
            }
        }
    }
    return temp;
}

mArray mArray::operator=(const mArray &right){ 
    Rows=right.Rows;
    Cols=right.Cols;
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
                Data[r][c]=right.Data[r][c];
        }
    }
    return *this; 
}

mArray mArray::logsig(const mArray &a){
    mArray temp(a.Rows,a.Cols);
    for(int r=0;r<a.Rows;r++){
        for(int c=0;c<a.Cols;c++){
                temp.Data[r][c]=1.0/(1.0+exp(-a.Data[r][c]));
        }
    }
    return temp;
}

mArray mArray::invMat(const mArray &m){
    mArray a(m.Rows,2*m.Cols);
    mArray mInv(m.Rows,m.Cols);
    for(int i=0;i<m.Rows;i++)
        for(int j=0;j<m.Cols;j++)
            a.setData(m.getData(i,j),i,j);
    for(int i=0;i<a.Rows;i++){
        for(int j=a.Rows;j<a.Cols;j++){
            if(i==j-a.Rows)a.setData(1,i,j);
            else a.setData(0,i,j);
        }
    }
    for(int i=0;i<a.Rows;i++){
        float t=a.getData(i,i);
        for(int j=i;j<a.Cols;j++)a.setData(a.getData(i,j)/t,i,j);
        for(int j=0;j<a.Rows;j++){
            if(i!=j){
                t=a.getData(j,i);
                for(int k=0;k<a.Cols;k++)
                    a.setData(a.getData(j,k)-t*a.getData(i,k),j,k);
            }
        }
    }
    for(int i=0;i<m.Rows;i++)
        for(int j=0;j<m.Cols;j++)
            mInv.setData(a.getData(i,j+a.Rows),i,j);
    return mInv;
}

int *mArray::sort(int c){
    int *indx=new int[Rows];
    for(int i=0;i<Rows;i++){
        indx[i]=i;
    }
    for(int i=0;i<Rows-1;i++){
        for(int j=i;j<Rows;j++){
            if(Data[indx[i]][c]>Data[indx[j]][c]){
                int temp=indx[i];
                indx[i]=indx[j];
                indx[j]=temp;
            }
        }
    }
    return indx;
}

void mArray::mPrint(char *fn){
    ofstream out;
    out.open(fn);
    out<<Rows<<" ";
    out<<Cols<<endl;
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
            out<<Data[r][c]<<" ";
        }
        out<<endl;
    }
    out.close();
}