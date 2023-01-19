#pragma once
#include "opencv2/opencv.hpp"

class LevelSet
{
public:
	LevelSet(const cv::Mat& src);
	//initialize level set
	void initializePhi(cv::Point2f center, float radius);
	int evolving();

private:
	int iterationnum_ = 3000;
	float lambda1_ = 1.0f;	 //weight for c1 fitting term
	float lambda2_ = 1.0f;   //weight for c2 fitting term
	float mu_ = 0.1 * 255 * 255;	//��: weight for length term������
	float nu_ = 0.0;  //��: weight for area term, default value 0 �����
	//float timestep_ = 1; //time step: ��t �촽����
	float timestep_ = 5; //time step: ��t �ɻ�����
	//float timestep_ = 5; //time step: ��t ͼ�경��
	//float timestep_ = 100; //time step: ��t ͼ�경��big
	//��: parameter for computing smooth Heaviside and dirac function
	float epsilon_ = 1.0;
	float c1_;	//average(u0) inside level set
	float c2_;	//average(u0) outside level set
	float forntpro_ = 0.1; //ǰ����ֵ����ϵ��
	cv::Mat phi_;		//level set: ��
	cv::Mat dirac_;		//dirac level set: ��(��)
	cv::Mat heaviside_;	//heaviside����(��)
	cv::Mat curv_;
	cv::Mat src_;
	cv::Mat image_; //for showing��ʾͼ��

	void gradient(const cv::Mat& src, cv::Mat& gradx, cv::Mat& grady);
	//Dirac function
	void dirac();
	//Heaviside function
	void heaviside();
	void calculateCurvature();
	//calculate c1 and c2
	void calculatC();
	//show evolving
	void showEvolving();
	void showLevelsetEvolving();
};