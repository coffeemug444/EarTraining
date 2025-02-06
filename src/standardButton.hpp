#pragma once
#include "button.hpp"
#include <functional>

class StandardButton : public Button
{
public:
   StandardButton(const std::string& name, std::function<void(void)> on_clicked, const int font_size)
      :Button(name, font_size)
      ,m_on_clicked(on_clicked)
   {}
protected:
   virtual void onClicked() override { m_on_clicked(); }

private:
   std::function<void(void)> m_on_clicked;
};