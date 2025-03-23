#pragma once

#include <ESP323248S035.hpp>

// The ESP32-3248S035 library defines View as a pure virtual class, which acts
// as an interface between the library and application GUI code.
//
// We must define a concrete implementation of View to act as the root window
// of the target device's GUI. The content of View is application-defined.
//
// NOTE: Do NOT make any lvgl API calls from the View constructor. These must be
//       performed in the View::init() method.
class Main: public bsp::View {
public:
  Main() = default;
  ~Main() = default;

  bool init(lv_obj_t *root) override {
    if (nullptr == root) {
      // Use the default screen if no root view provided.
      root = lv_scr_act();
    }
    lv_obj_t *label = lv_label_create(root);
    // lv_obj_center(label);
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x003a57), LV_PART_MAIN);
    // lv_label_set_text(label, "Proximo display para lograr\nla interface de la unidad\nenfriadora capilar ambulatoria");
    lv_example_tileview_1();
    return true;
  }

  void update(msecu32_t const now) override {
    // Update any subviews here.
  }

  void lv_example_tileview_1(void)
  {
      lv_obj_t * tv = lv_tileview_create(lv_screen_active());
  
      /*Tile1: just a label*/
      lv_obj_t * tile1 = lv_tileview_add_tile(tv, 0, 0, LV_DIR_BOTTOM);
      lv_obj_t * label = lv_label_create(tile1);
      lv_label_set_text(label, "Desplazate abajo");
      lv_obj_center(label);
  
      /*Tile2: a button*/
      lv_obj_t * tile2 = lv_tileview_add_tile(tv, 0, 1, (lv_dir_t)(LV_DIR_TOP | LV_DIR_RIGHT));
  
      lv_obj_t * btn = lv_button_create(tile2);
  
      label = lv_label_create(btn);
      lv_label_set_text(label, "Desplazar hacia Arriba o derecha");
  
      lv_obj_set_size(btn, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_obj_center(btn);
  
      /*Tile3: a list*/
      lv_obj_t * tile3 = lv_tileview_add_tile(tv, 1, 1, LV_DIR_LEFT);
      lv_obj_t * list = lv_list_create(tile3);
      lv_obj_set_size(list, LV_PCT(100), LV_PCT(100));
  
      lv_list_add_button(list, NULL, "Primer Item");
      lv_list_add_button(list, NULL, "Segundo Item");
      lv_list_add_button(list, NULL, "Tercer Item");
      lv_list_add_button(list, NULL, "Cuarto Item");
      lv_list_add_button(list, NULL, "Quinto Item");
      lv_list_add_button(list, NULL, "Sexto Item");
      lv_list_add_button(list, NULL, "Septimo Item");
      lv_list_add_button(list, NULL, "Octavo Item");
      lv_list_add_button(list, NULL, "Noveno Item");
      lv_list_add_button(list, NULL, "Decimo Item");
  
  }
  

  std::string title() override {
    return "Main";
  }
};

Main root;
//bsp::ESP323248S035C target(root); // C++17 can deduce template parameter.
bsp::ESP323248S035C<Main> target(root); // Pre-C++17 requires explicit type.
