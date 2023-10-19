function calculateCost() {
    // Получение значений из формы
    var quantity = document.getElementById("quantity").value;
    var product = document.getElementById("product").value;

    // Расчет стоимости заказа
    var price;
    if (product === "product1") {
        price = 90000; //Цена за Фотоаппарат
    } else if (product === "product2") {
        price = 15000; // Цена за Камеру
    } else if (product === "product3") {
        price = 135000; // Цена за Телефон
    }
    else if (product === "product4") {
        price = 20000; // Цена за Полароид

    }
    var totalCost = quantity * price;

    // Вывод стоимости заказа на страницу
    document.getElementById("result").innerHTML = "Стоимость заказа: " + totalCost + " руб.";
}





