# 输出贝祖等式gcd(a,b)=ma+nb的整数常数m，n
def extendedEuclidean(a, b):
    if (b == 0):  # 边界条件
        return 1, 0  # 返回（1，0）因为g = 1×a +0× 0
    else:
        m, n = extendedEuclidean(b, a % b)  # 找到b和r的贝祖等式常数（m,n）
        quotient = a//b  # 计算a与b的整数商
        return n, m - (n * quotient)


a, b = extendedEuclidean(10, 15)
print(a, b)
