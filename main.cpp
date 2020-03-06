#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

int main() {
    int m = 17;
    int n = 5;
    double data[17][5] = {
            13.6, 14.01, 14.54, 14.64, 15.69,
            11.50, 13.00, 15.15, 15.30, 15.02,
            13.76, 16.36, 16.90, 16.56, 17.30,
            12.41, 12.70, 13.96, 14.04, 13.46,
            2.48, 2.49, 2.56, 2.64, 2.59,
            85, 85, 90, 100, 105,
            55, 65, 75, 80, 80,
            65, 70, 75, 85, 90,
            12.80, 15.30, 16.24, 16.40, 17.05,
            15.30, 18.40, 18.75, 17.95, 19.30,
            12.71, 14.50, 14.66, 15.88, 15.70,
            14.78, 15.54, 16.03, 16.87, 17.82,
            7.64, 7.56, 7.76, 7.54, 7.70,
            120, 125, 130, 140, 140,
            80, 85, 90, 90, 95,
            4.02, 4.25, 4.1, 4.06, 3.99,
            13.1, 13.42, 12.85, 12.72, 12.56
    };

    // step1: 数据归一化
    for (int i = 0; i < m - 2; ++i) {
        double s = data[i][0];
        for (int j = 0; j < n; ++j) {
            data[i][j] /= s;
        }
    }

    for (int i = m-2; i < m; ++i) {
        double s = data[i][0];
        for (int j = 0; j < n; ++j) {
            data[i][j] = s / data[i][j];
        }
    }

    // step2: 计算关联系数
    double max_interval = -100;
    double min_interval = 100;
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            double interval = fabs(data[i][j] - data[0][j]);
            if (interval > max_interval) {
                max_interval = interval;
            }
            if (interval < min_interval) {
                min_interval = interval;
            }

            cout << interval << " ";
        }
        cout << endl;
    }

    cout << "maxInterval = " << max_interval << endl;
    cout << "minInterval = " << min_interval << endl;

    double ksi[16][5];
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ksi[i-1][j] = (min_interval + 0.5 * max_interval) / (fabs(data[0][j] - data[i][j]) + 0.5 * max_interval);
            cout << ksi[i-1][j] << " ";
        }
        cout << endl;
    }

    // step2: 计算关联度
    cout << "ksi0 = " << ksi[0][0];
    for (int k = 0; k < m-1; ++k) {
        double x = 0.0;
        for (int i = 0; i < n; ++i) {
           x += ksi[k][i];
        }

        x /= n;
        cout << x << endl;
    }

    cout << data << endl;
}