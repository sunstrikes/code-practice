#include <utility>

//
// Created by Sun,Minqi on 2021/5/26.
//

#ifndef TEST_HTML_ELEMENT_H
#define TEST_HTML_ELEMENT_H

class HtmlElement {
public:
    std::string name;
    std::string text;
    std::vector<HtmlElement> elements;

    [[nodiscard]] std::string str(int indent = 0) const {
        std::string res;
        if (!elements.empty()) {
            res = "{";
            for (auto &x: elements) {
                res += x.name + std::string(": ") + x.text + std::string(" ");
            }
            res.append("}");
        }
        return res;
    }

    HtmlElement(std::string name, std::string text)
            : name(std::move(name)), text(std::move(text)) {}
    HtmlElement() = default;

};

class FluentBuilder{
public:
    HtmlElement _root;
    explicit FluentBuilder(const std::string& root_name) {
        _root.name = root_name;
    }
    FluentBuilder& add_tag(const std::string& name, const std::string& text) {
        _root.elements.emplace_back(name, text);
        return *this;
    }
    FluentBuilder* add_tag2(const std::string& name, const std::string& text) {
        _root.elements.emplace_back(name, text);
        return this;
    }
    void print() const {
        std::cout << _root.str() << std::endl;
    }
};
#endif //TEST_HTML_ELEMENT_H
