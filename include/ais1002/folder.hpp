
#ifndef FOLDER_DEMO_FOLDER_HPP
#define FOLDER_DEMO_FOLDER_HPP

#include <functional>
#include <string>
#include <vector>

namespace ais1002 {

    class folder {

    public:
        explicit folder(std::string path) : path_(std::move(path)) {}

        [[nodiscard]] std::string getRelativePath() const {

            return path_;
        }

        [[nodiscard]] size_t numChildren() const {

            return children_.size();
        }

        std::string getAbsolutePath() {
            std::string absolute;
            traverseUpwards([&](folder *f) {
                absolute.insert(0, f->path_ + "/");
            });
            return absolute;
        }

        void add(folder &f) {
            f.parent_ = this;// this -> folder*
            children_.emplace_back(&f);
        }

        [[nodiscard]] bool isRoot() const {

            return !hasParent();
        }

        [[nodiscard]] bool isLeaf() const {

            return children_.empty();
        }

        [[nodiscard]] bool hasParent() const {

            return parent_ != nullptr;
        }

        void remove(folder *folder) {

            auto find = std::find(children_.begin(), children_.end(), folder);
            if (find != children_.end()) {
                children_.erase(find);
            }
            folder->parent_ = nullptr;
        }

        void removeFromParent() {
            if (parent_) {
                parent_->remove(this);
            }
        }

        void traverseUpwards(const std::function<void(folder *)> &f) {
            f(this);
            if (hasParent()) {
                parent_->traverseUpwards(f);
            }
        }

        void traverseDepthFirst(const std::function<void(folder *)> &f) {
            f(this);
            for (auto c: children_) {
                c->traverseDepthFirst(f);
            }
        }

    private:
        std::string path_;

        // note: NON owning pointers
        folder *parent_ = nullptr;
        std::vector<folder *> children_;
    };

}// namespace ais1002

#endif//FOLDER_DEMO_FOLDER_HPP
