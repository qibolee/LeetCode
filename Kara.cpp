//
// Created by qibolee on 11/26/16.
//

#include "Kara.h"

const std::string add2(const std::string &p, const std::string &q) {
    int tmp = 0;
    std::string res(std::max(p.size(), q.size()) + 1, '0');
    for (int i = 0; i < res.size(); ++i) {
        if (i < p.size()) {
            tmp += p[i] - '0';
        }
        if (i < q.size()) {
            tmp += q[i] - '0';
        }
        res[i] = tmp % 10 + '0';
        tmp /= 10;
    }
    if (res.back() == '0') {
        res.resize(res.size() - 1);
    }
    return res;
}

const std::string add(const std::string &p, const std::string &q) {
    auto tp(p);
    auto tq(q);
    std::reverse(tp.begin(), tp.end());
    std::reverse(tq.begin(), tq.end());
    auto res = add2(tp, tq);
    std::reverse(res.begin(), res.end());
    return res;
}

const std::string sub2(const std::string &p, const std::string &q) {
    int tmp = 0;
    std::string res(p.size(), '0');
    for (int i = 0; i < p.size(); ++i) {
        tmp += p[i] - '0';
        if (i < q.size()) {
            tmp -= q[i] - '0';
        }
        if (tmp < 0) {
            res[i] = tmp + 10 + '0';
            tmp = -1;
        } else {
            res[i] = tmp + '0';
            tmp = 0;
        }
    }
    auto ptr = std::find_if(res.rbegin(), res.rend(), [](const char ch) { return ch != '0'; });
    int cnt = ptr - res.rbegin();
    res.resize(res.size() - cnt);
    return res;
}

const std::string sub(const std::string &p, const std::string &q) {
    auto tp(p);
    auto tq(q);
    std::reverse(tp.begin(), tp.end());
    std::reverse(tq.begin(), tq.end());
    auto res = sub2(tp, tq);
    std::reverse(res.begin(), res.end());
    return res;
}

const std::string kara(const std::string &p, const std::string &q) {
    if (p.empty() || q.empty()) {
        return std::string();
    }
    if (p.size() < 8 && q.size() < 8) {
        long long tmp = std::stoll(p) * std::stoll(q);
        return std::to_string(tmp);
    }
    size_t len = (std::max(p.size(), q.size()) + 1) / 2;
    std::string a;
    std::string b;
    std::string c;
    std::string d;
    if (p.size() > len) {
        a = p.substr(0, p.size() - len);
        b = p.substr(p.size() - len);
    } else {
        b = p;
    }
    if (q.size() > len) {
        c = q.substr(0, q.size() - len);
        d = q.substr(q.size() - len);
    } else {
        d = q;
    }
    std::string ac = kara(a, c);
    std::string bd = kara(b, d);
    std::string cum = kara(add(a, b), add(c, d));
    cum = sub(cum, ac);
    cum = sub(cum, bd);
    std::string res = ac + std::string(len * 2, '0');
    res = add(res, cum + std::string(len, '0'));
    res = add(res, bd);
    return res;
}
