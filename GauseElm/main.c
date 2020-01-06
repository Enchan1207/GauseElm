//
//  main.c
//  GauseElm - ガウスの消去法による連立方程式の計算
//
//  Created by EnchantCode on 2020/01/06.
//  Copyright © 2020 EnchantCode. All rights reserved.
//

#include <stdio.h>

void cat(double dat[4][5]);

int main(int argc, const char * argv[]) {

    //--係数行列
    double coef[4][5] = {
        { 4,  1, -3,  5,  17}, //1
        { 2,  3,  1,  2,  19}, //2
        { 5, -4, -2,  1,  -5}, //3
        {-2,  2,  8,  2,  34}  //4
    };
    
    //--全身消去
    for(int k = 0; k < 4; k++){
        //--1. 第k式の第k項の係数を1にする
        double base = coef[k][k];
        for(int i = 0; i < 5; i++){
            coef[k][i] /= base;
        }
        
        //--2. それぞれの式の第k項(xk)を消す
        for(int i = k + 1; i < 4; i++){
            //--第k式の倍数を計算し、新規配列を用意 + coef - tmp
            double exp = coef[i][k] / coef[k][k];
            for(int j = 0; j < 5; j++){
                coef[i][j] -= (coef[k][j] * exp);
            }
        }
    }
    
    //--後退代入
    //解の配列
    double ans[4] = {0, 0, 0, 0};
    
    //解4はすでに出ている
    ans[3] = coef[3][4];
    
    //解3を出す
    ans[2] = coef[2][4] - coef[2][3] * ans[3];
    
    //解2を出す
    ans[1] = coef[1][4] - coef[1][2] * ans[2] - coef[1][3] * ans[3];
    
    //解1を出す
    ans[0] = coef[0][4] - coef[0][1] * ans[1] - coef[0][2] * ans[2] - coef[0][3] * ans[3];
    
    cat(coef);
    
    for(int i = 0; i < 4; i++){
        printf("x%d = %.2lf\n", i + 1, ans[i]);
    }
    
    return 0;
}

//--配列を吐き出す
void cat(double dat[4][5]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            printf("%.2lf ", dat[i][j]);
            if(j == 3){
                printf(" = ");
            }
        }
        printf("\n");
    }
    
}
