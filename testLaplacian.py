"""
	Laplacian関数の動作を確認するツール
"""
import cv2
import numpy as np

import sys
print(sys.argv)
if (len(sys.argv)<5):
	print("few params")
	exit(1)
dp = int(sys.argv[2]);
sz = int(sys.argv[3]);
tag = sys.argv[4];

print("file=",sys.argv[1])
depth = [
	cv2.CV_8U, cv2.CV_32F, cv2.CV_64F
]
size = [1,3,5,7]
f = sys.argv[1]
# 画像を読み込む
#img = cv2.imread("./lena_std.bmp")
img = cv2.imread(f)
img1 = cv2.Laplacian(img, depth[dp] , size[sz])

#img2 = cv2.Laplacian(img, cv2.CV_8U, ksize=3)
#img3 = cv2.Laplacian(img, cv2.CV_8U, ksize=5)
#img4 = cv2.Laplacian(img, cv2.CV_32F, ksize=3)
#img5 = cv2.Laplacian(img, cv2.CV_32F, ksize=5)
#img6 = cv2.Laplacian(img, cv2.CV_64F, ksize=3)
#cv2.CV_8U, ksize=5

# 読み込んだ画像を表示する
cv2.imshow(tag, img1)
#if True:
#	cv2.imshow('imshow_test2', img2)
#	cv2.imshow('imshow_test3', img3)
#	cv2.imshow('imshow_test4', img4)
#	cv2.imshow('imshow_test5', img5)
#	cv2.imshow('imshow_test6', img6)

# キーボードが押されるまで、処理を止める
cv2.waitKey(0)

# ウィンドウを閉じる
cv2.destroyAllWindows()
