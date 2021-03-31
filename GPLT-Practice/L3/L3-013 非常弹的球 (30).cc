#include <bits/stdc++.h>

static constexpr double GRAVITY = 9.8;
static constexpr double MAX_ALPHA = 0.5;

/** physical and mathematical question
 * RES = s + s*(1-p) + s*(1-p)*(1-p) + ...
 *     = s*[1 + (1-p) + (1-p)*(1-p) + ...]
 *     = s/p
 * v1 = sin(a) * v, v2 = cos(a) * v
 * t1 = v1/g, t = 2*t1 = 2*v1/g
 * s = t*v2 = 2*v1*v2/g
 *
 * Then, RES = 2*(v^2)/(g*p) * max{ sin(a)*cos(a) }
 * where max{ sin(a)*cos(a) } = 0.5, a = pi/4
 */
class ThrowBall {
private:
    double energy = 1000.0;
    double mass, loss;

public:
    ThrowBall() {
        std::cin >> this->mass >> this->loss;
        this->mass /= 100.0;
        this->loss /= 100.0;
    }

    double process() {
        double v = sqrt(this->energy * 2 / this->mass);
        return 2 * pow(v, 2) / (GRAVITY * this->loss) * MAX_ALPHA;
    }
};

int main(int argc, char const *argv[]) {
    ThrowBall tb;
    std::cout << std::fixed << std::setprecision(3) << tb.process() << '\n';
    return 0;
}
