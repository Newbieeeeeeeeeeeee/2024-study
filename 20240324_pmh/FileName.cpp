
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // ���� ũ�� ����
    int width = 256;
    int height = 256;

    // �׷��̽����� �̹��� ���� �� �ʱ�ȭ (���: 255)
    Mat image(height, width, CV_8UC1, Scalar(255));

    // 1. �밢�� ������ Xǥ �׸��� (������: 0)
    for (int row = 0; row < height; row++) {
        // ��Ī�Ǵ� ���� �� ��
        int col_symmetric = height - row - 1;
        // ��Ī�Ǵ� ���� �밢�� �׸���
        image.at<uchar>(row, row) = 0;
        image.at<uchar>(row, col_symmetric) = 0;
        // �̹��� ���
        imshow("Image", image);
        waitKey(10); // 10ms ���
    }
    waitKey();
    // 2. �� ������ 20�پ� �ǳʶٸ� ��������� ���� �׸��� (������: 0)
    for (int row = 0; row < height; row += 20) {
        uchar* row_ptr = image.ptr<uchar>(row); // ���� ���� ���� ���� �ּ�
        for (int col = 0; col < width; col++) {
            row_ptr[col] = 0; // ���������� �ȼ� ����
        }
        // �̹��� ���
        imshow("Image", image);
        waitKey(10);
    }

    // 3. ���߾ӿ� ũ�� 80X80ũ���� ���簢�� �׸��� (ȸ�� : 128)
    waitKey();
    int square_size = 80;
    int x = (width - square_size) / 2;
    int y = (height - square_size) / 2;
    Rect roi_rect(x, y, square_size, square_size);
    Mat roi = image(roi_rect);
    for (MatIterator_<uchar> it = roi.begin<uchar>(); it != roi.end<uchar>(); ++it) {
        // �ȼ� ������ 128�� ����, ������ ��� 0���� ����
        *it = max(static_cast<int>(*it) - 128, 0);
    }

    // �̹��� ���
    imshow("Image", image);
    waitKey();

    return 0;
}