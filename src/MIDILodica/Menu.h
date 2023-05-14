class Menu {
  public:
    const char* menuName;
    byte submenuTarget;
    void (*onAction)(byte target);
    int (*getSelectedMenu)();
    Menu(const char* menuName, byte submenuTarget, void (*onAction)(byte target), int (*getSelectedMenu)()) {
      this -> menuName = menuName;
      this -> submenuTarget = submenuTarget;
      this -> onAction = onAction;
      this -> getSelectedMenu = getSelectedMenu;
    }
};
