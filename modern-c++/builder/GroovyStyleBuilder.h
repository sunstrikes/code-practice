//
// Created by Sun,Minqi on 2021/5/27.
//

#ifndef TEST_GROOVYSTYLEBUILDER_H
#define TEST_GROOVYSTYLEBUILDER_H

struct Tag {
    std::string name;
    std::string text;
    std::vector <Tag> children;
    std::vector <std::pair<std::string, std::string>>
            attributes;

    friend std::ostream &operator<<(std::ostream &os,
                                    const Tag &tag) {
        std::string res;
        res = "{";
        if (!tag.children.empty()) {
            for (auto &x: tag.children) {
                res += x.name + std::string(": ") + x.text + std::string(" ");
            }
        } else {
            res += tag.text;
        }
        res.append("}");
        os << res;
        return os;
    }

protected:
    Tag(std::string name, std::string text): name(std::move(name)), text(std::move(text)) {
        children.clear();
        attributes.clear();
    }
    Tag(std::string name, const std::vector<Tag>& child): name(std::move(name)), children(child) {}
};

struct RL: public Tag{
    explicit RL(std::string text): Tag("RL", text) {}
    RL(std::initializer_list<Tag> child): Tag("RL", child){
        std::cout << "initializer list constuct func" << std::endl;
    }
};

struct TL: public Tag{
    explicit TL(std::string text): Tag("TL", text){}
};
#endif //TEST_GROOVYSTYLEBUILDER_H
