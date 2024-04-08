#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void main() {
	Mat image(300, 500, CV_8UC1, Scalar(255)); // (300, 500) ũ���� �迭�� �����ϰ� 255�� �ʱ�ȭ
	Point2f center(250, 150), pts[4];
	Size2f size(200, 80);
	RotatedRect rot_rect(center, size, 60);
	circle(image, rot_rect.center, 1, Scalar(0), 2); // image �� ror_rect�� ���Ϳ� �� �׸���, ������1, ��� 0, �β� 2
	rot_rect.points(pts); // �迭 pts�� ȸ���簢���� 4���� ��ȯ
	cout << "point = " << endl;

	for (int i = 0; i < 4; i++)
		cout << pts[i] << ", " << endl; // 4���� ��ǥ ���
	for (int i = 0; i < 4; i++) {
		circle(image, pts[i], 5, Scalar(0), 2); // image�� ȸ���簢�� 4���� �� �׸���, ������ 4, �β� 1
		line(image, pts[i], pts[(i + 1) % 4], Scalar(0), 2); // ���� 4�� �׸���
	}

	Rect bound_rect = rot_rect.boundingRect();
	rectangle(image, bound_rect, Scalar(0), 1);
	circle(image, Point(bound_rect.x, bound_rect.y), 5, Scalar(0), 2);
	circle(image, Point(bound_rect.x+bound_rect.width, bound_rect.y), 5, Scalar(0), 2);
	circle(image, Point(bound_rect.x+bound_rect.width, bound_rect.y+bound_rect.height), 5, Scalar(0), 2);
	circle(image, Point(bound_rect.x, bound_rect.y+bound_rect.height), 5, Scalar(0), 2);
	line(image, Point(250,0), Point(250,300), Scalar(0), 1); // ù ��° ��
	line(image, Point(0,150), Point(500,150), Scalar(0), 1); // �� ��° ��
	imshow("ȸ���簢��", image); // image�� â�� ����� ���
	waitKey(0);
}
	