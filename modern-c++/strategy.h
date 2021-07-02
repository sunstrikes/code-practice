//
// Created by Sun,Minqi on 2021/6/29.
//

#pragma once

#include "util.h"

namespace strategy {
    struct DynamicStrategy {
        virtual void pre_process(std::ostringstream &oss) {}

        virtual void process(std::ostringstream &oss, const std::string& item) {}

        virtual void post_process(std::ostringstream &oss) {}
    };

    struct MarkdownStrategy : DynamicStrategy {
        void process(std::ostringstream &oss,
                     const std::string &item) override {
            oss << " * " << item << std::endl;
        }
    };

    struct HtmlStrategy : DynamicStrategy {
        void pre_process(std::ostringstream &oss) override {
            oss << "<ul>\n";
        }

        void post_process(std::ostringstream &oss) override {
            oss << "</ul>\n";
        }

        void process(std::ostringstream &oss, const std::string &item) override {
            oss << "<Li>" << item << "</Li>" << std::endl;
        }
    };
    enum class OutputFormat{
        HTML,
        MD
    };
    struct TextProcessor {
        void append_list(const std::vector<std::string> &items) {
            list_strategy->pre_process(oss);
            for (auto& item: items) {
                list_strategy->process(oss, item);
            }
            list_strategy->post_process(oss);
        }
        void set_format(OutputFormat format) {
            switch(format) {
                case OutputFormat::HTML:
                    list_strategy = std::make_unique<HtmlStrategy>();
                    break;
                case OutputFormat::MD:
                    list_strategy = std::make_unique<MarkdownStrategy>();
                    break;
            }
        }
        std::string str() {
            return oss.str();
        }
    private:
        std::ostringstream oss;
        std::unique_ptr<DynamicStrategy> list_strategy;
    };

    //static strategy
    template<class LS>
    struct TextProcessor2 {
        void append_list(const std::vector<std::string> &items) {
            list_strategy->pre_process(oss);
            for (auto& item: items) {
                list_strategy->process(oss, item);
            }
            list_strategy->post_process(oss);
        }

        std::string str() {
            return oss.str();
        }
    private:
        std::ostringstream oss;
        LS list_strategy;
    };
}