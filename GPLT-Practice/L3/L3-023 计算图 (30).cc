#include <bits/stdc++.h>

class ComputationalGraph {
private:
    struct Op {
        size_t type;
        double varValue = 0.0;                    // type 0
        std::pair<size_t, size_t> dep = {-1, -1}; // type 1~6, type 1~3
    };
    size_t n;
    std::vector<Op> ops;

    std::unordered_set<size_t> variables;
    std::vector<std::vector<double>> value;

public:
    ComputationalGraph() {
        std::cin >> this->n;
        this->ops.resize(this->n);
        this->value.push_back(std::vector<double>(this->n));

        for (size_t i = 0; i < this->n; ++i) {
            std::cin >> this->ops[i].type;
            if (0 == this->ops[i].type) {
                std::cin >> this->ops[i].varValue;
                this->variables.insert(1 + this->variables.size());
                this->value[0][i] = this->ops[i].varValue;
                this->value.push_back(std::vector<double>(this->n));
                this->value.back()[i] = 1.0;
            } else {
                std::cin >> this->ops[i].dep.first;
                if (this->ops[i].type < 4) std::cin >> this->ops[i].dep.second;
            }
        }
    }

    std::vector<double> process() {
        size_t _exit = this->findExit();
        this->calculate(_exit);

        auto res = std::vector<double>(1 + this->variables.size());
        for (size_t i = 0; i <= this->variables.size(); ++i) res[i] = this->value[i][_exit];
        return res;
    }

private:
    size_t findExit() {
        bool *required = new bool[this->n]{};
        for (auto &&op : this->ops) {
            if (0 == op.type) continue;
            required[op.dep.first] = true;
            if (op.type > 3) continue;
            required[op.dep.second] = true;
        }
        size_t index = std::find(required, required + this->n, false) - required;
        delete[] required;
        return index;
    }

    void calculate(size_t i) {
        auto &val = this->value;
        auto isCalculated = [i](const std::vector<double> &v) { return 0.0 != v[i]; };
        if (std::any_of(val.begin(), val.end(), isCalculated)) return;

        size_t j = this->ops[i].dep.first, k;
        this->calculate(j);

        if (this->ops[i].type < 4) {
            k = this->ops[i].dep.second;
            this->calculate(k);
        }

        switch (this->ops[i].type) {
            case 1: // +
                val[0][i] = val[0][j] + val[0][k];
                for (auto &&v : variables) val[v][i] = val[v][j] + val[v][k];
                break;
            case 2: // -
                val[0][i] = val[0][j] - val[0][k];
                for (auto &&v : variables) val[v][i] = val[v][j] - val[v][k];
                break;
            case 3: // *
                val[0][i] = val[0][j] * val[0][k];
                for (auto &&v : variables) val[v][i] = val[v][j] * val[0][k] + val[0][j] * val[v][k];
                break;
            case 4: // exp
                val[0][i] = std::exp(value[0][j]);
                for (auto &&v : variables) val[v][i] = val[v][j] * val[0][i];
                break;
            case 5: // ln
                val[0][i] = std::log(val[0][j]);
                for (auto &&v : variables) val[v][i] = val[v][j] / val[0][j];
                break;
            case 6: // sin
                val[0][i] = std::sin(value[0][j]);
                for (auto &&v : variables) val[v][i] = val[v][j] * std::cos(val[0][j]);
                break;
        }
    }
};

int main() {
    ComputationalGraph cg;
    auto res = cg.process();

    std::cout << std::fixed << std::setprecision(3);
    std::cout << res[0];
    for (size_t i = 1; i < res.size(); ++i) std::cout << (1 == i ? "\n" : " ") << res[i];

    return 0;
}
