void drawMenu() {
  tft.setTextSize(2);

  if (currentNumberSelectMenu >= 0) {
    allNumberSelectMenus[currentNumberSelectMenu].onLoad();
    return;
  }

  tft.fillScreen(backgroundColor);

  int previousMenuItem = currentMenuItem - 1;
  if (previousMenuItem < 0) {
    previousMenuItem = menuLengths[currentMenu] - 1;
  }

  int nextMenuItem = currentMenuItem + 1;
  if (nextMenuItem > menuLengths[currentMenu] - 1) {
    nextMenuItem = 0;
  }

  // Highlight the currently selected menu item.
  tft.fillRect(0, 60, tft.width(), 50, selectedColor);

  drawTextWithShadow(allMenus[currentMenu][previousMenuItem].menuName, 15, 33);
  drawTextWithShadow(allMenus[currentMenu][currentMenuItem].menuName, 15, 93);
  drawTextWithShadow(allMenus[currentMenu][nextMenuItem].menuName, 15, 153);

  int selectedMenu = allMenus[currentMenu]->getSelectedMenu();

  if (selectedMenu == -1) {
    return;
  }

  if (previousMenuItem == selectedMenu) {
    tft.drawCircle(tft.width() - 30, 25, 10, selectedColor);
  }

  if (currentMenuItem == selectedMenu) {
    tft.drawCircle(tft.width() - 30, 85, 10, 0x1ad2);
  }

  if (nextMenuItem == selectedMenu) {
    tft.drawCircle(tft.width() - 30, 145, 10, selectedColor);
  }
}
