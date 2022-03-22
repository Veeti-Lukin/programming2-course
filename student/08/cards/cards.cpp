#include "cards.hh"

// TODO: Implement the methods here

Cards::Cards(): top_(nullptr)
{

}

Card_data *Cards::get_topmost()
{
    return top_;
}

void Cards::add(int id)
{
    Card_data* new_card = new Card_data{id, top_};
    top_ = new_card;
}

void Cards::print_from_top_to_bottom(std::ostream &s)
{
    Card_data* item_to_be_printed = top_;
    int running_number = 1;

    while (item_to_be_printed != nullptr) {
        s << running_number << ": " << item_to_be_printed->data <<  std::endl;
        ++running_number;
        item_to_be_printed = item_to_be_printed->next;
    }
}

bool Cards::remove(int &id)
{
    if (top_ == nullptr ) {
        return false;
    }
    Card_data* item_to_be_removed = top_;
    id = item_to_be_removed->data;

    top_ = top_->next;
    delete item_to_be_removed;
    return true;;
}

bool Cards::bottom_to_top()
{
    if (top_ == nullptr ) {
        return false;
    }

    Card_data* current_card = top_;
    Card_data* previous_card = top_;
    while (current_card->next != nullptr) {
        previous_card = current_card;
        current_card = current_card->next;
    }
    previous_card->next = nullptr;
    current_card->next = top_;
    top_ = current_card;
    return true;
}

bool Cards::top_to_bottom()
{
    if (top_ == nullptr || top_->next == nullptr ) {
        return false;
    }
    Card_data* temp = top_;
    Card_data* current_card = top_;
    top_ = top_->next;

    while (current_card->next != nullptr) {
        current_card = current_card->next;
    }
    current_card->next = temp;
    temp->next = nullptr;
    return true;
}

void Cards::print_from_bottom_to_top(std::ostream &s)
{
    recursive_print(top_, s);
}


Cards::~Cards()
{
    while (top_ != nullptr) {
        Card_data* temp = top_;
        top_ = top_->next;

        delete temp;
    }
}

int Cards::recursive_print(Card_data *top, std::ostream &s)
{
    int index = 1;
    if (top->next != nullptr) {
        index += recursive_print(top->next, s);
    }
    s << index << ": " <<  top->data << std::endl;
    return index;
}


