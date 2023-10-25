function calculateCost() {
    // Получение значений из формы
    var quantity = parseInt(document.getElementById("quantity").value);
    var product = document.querySelector('input[name="product"]:checked').value;
    var option = document.getElementById("option").value;
    var property = document.getElementById("property").checked;

    // Расчет стоимости заказа
    var price = 0;
    if (product === "product1") {
        price = 90000 * quantity; //Цена за Фотоаппарат
    } else if (product === "product2") {
        price = 15000 * quantity;// Цена за Камеру
        price += option === "option0" ? 0 : 0;
        price += option === "option1" ? 5000 : 0;
        price += option === "option2" ? 3000 : 0;
        price += option === "option3" ? 1700 : 0;
        price += option === "option4" ? 7000 : 0;
        price += option === "option5" ? 4000 : 0;
    } else if (product === "product3") {
        price = 135000 * quantity;// Цена за Телефон
        price += property ? 6000 : 0;
    }
    else if (product === "product4") {
        price = 20000 * quantity; // Цена за Полароид
        price += option === "option0" ? 0 : 0;
        price += option === "option1" ? 5000 : 0;
        price += option === "option2" ? 3000 : 0;
        price += option === "option3" ? 1700 : 0;
        price += option === "option4" ? 7000 : 0;
        price += option === "option5" ? 4000 : 0;
        price += property ? 6000 : 0;
    }
    else if (product === "product5") {
        price = 110000 * quantity; // Цена за Полароид
        price += option === "option0" ? 0 : 0;
        price += option === "option1" ? 5000 : 0;
        price += option === "option2" ? 3000 : 0;
        price += option === "option3" ? 1700 : 0;
        price += option === "option4" ? 7000 : 0;
        price += option === "option5" ? 4000 : 0;
        price += property ? 6000 : 0;
    }

    // Обновление отображения цены
    document.querySelector(".price h5").textContent = "Цена: " + price + " руб.";
}












