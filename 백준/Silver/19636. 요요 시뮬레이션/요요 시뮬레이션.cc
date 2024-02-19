#include <iostream>
#include <cmath>
// 검색해서 cmath라는 걸 알게 됨
// 기초대사량 변화 반영이 안될 때 : 무게 += 일일 에너지 섭취량 - (기초대사량 + 활동 대사량)
// 기초대사량 변화 반영 : 무게 += 일일 에너지 섭취량 -(기초대사량+활동대사량)
// 위 절댓값이 T 초과 : 기초대사량은 (E 섭취량 - 에너지 소비량)/2 만큼 더해짐

using namespace std;

int main(){
    int weight, meta, T, D, d_in, d_out;

    cin >> weight >> meta >> T;
    cin >> D >> d_in >> d_out;

    int fWeight = weight;
    int sWeight = weight;
    int sMeta = meta;

    for (int i=0; i<D; i++){
        fWeight += d_in - (meta + d_out);
        sWeight += d_in - (sMeta + d_out);
        if (abs(d_in - (sMeta + d_out)) > T)
            sMeta += floor((d_in - (sMeta+d_out))/2.0);
    }

    if (fWeight <= 0)
        cout << "Danger Diet\n";
    else
        cout << fWeight << " " << meta << "\n";

    if (sWeight <= 0 || sMeta <= 0)
        cout << "Danger Diet\n";
    else{
        cout << sWeight << " " << sMeta << " ";
        if (meta > sMeta)
            cout << "YOYO";
        else
            cout << "NO";
    }
}