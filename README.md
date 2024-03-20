<h1>GetHealth App</h1>

<h2 style="text-align: center">Про проєкт</h2>

<div><b>Назва:</b> GetHeath</div>
<div>
    <b>Опис:</b> 
    <u>GetHeath</u> - це десктопний додаток для покращення ефективності отримання медичних послуг, що надає можливість пацієнту легко та без черг реєструватися на прийом до лікаря. Користувачі мають можливість створити особистий кабінет з необхідною інформацією (та редагувати ії), обирати необхідого лікаря, уточнюючи нюанси (наприклад, запис на консультацію чи лікування) та реєструватися на прийом.а     
</div>

<h2 style="text-align: center">Вимоги до проєкту</h2>
<h3 style="text-align: center">Функціональні вимоги</h3>

<div id="pages">
    <b><u>Сторінки</u></b>
    <div>Додаток має сторінки:</div>
    <ul>
        <li>Авторизація</li>
        <li>Реєстрація</li>
        <li>Особистий кабінет</li>
        <li>Мої записи</li>
        <li>Створення запису</li>
    </ul>
</div><br>



<div id="menu">
    <b><u>Меню</u></b><br>
    <span>
        <i><u>Опис:</u></i> 
        у навігаційному меню додатку є пункти:
        <ul>
            <li>Особистий кабінет</li>
            <li>Мої записи</li>
        </ul>
    <span>
        <i><u>Дії програми:</u></i> 
        при натисканні на пункт меню відбувається перехід на необхідну сторінку
    </span>
</div><br><br>



<div id="page-registr">
    <b><u>Сторінка “Регістрація”</u></b><br>
    <span>
        <i><u>Опис:</u></i> 
        на сторінці “Регістрація” знаходяться:
        <ul>
            <li>поле вводу “Ім'я” - <span style="color: #85200c;"><u>обов’язкове поле</u></span>
                <ul style="list-style: none">
                    <li>
                        <i>Детальніше:</i> ім'я не повинно перевищувати 10 символів
                    </li>
                </ul>
            </li>
            <li>поле вводу “Прізвище” - <span style="color: #85200c;"><u>обов’язкове поле</u></span>
                <ul style="list-style: none">
                    <li>
                        <i>Детальніше:</i> прізвище не повинно перевищувати 20 символів
                    </li>
                </ul>
            </li>
            <li>поле вводу “По батькові” - <span style="color: #85200c;"><u>обов’язкове поле</u></span>
                <ul style="list-style: none">
                    <li>
                        <i>Детальніше:</i> по батькові не повинно перевищувати 15 символів
                    </li>
                </ul>
            </li>
            <li>вибір дати народження - <span style="color: #85200c;"><u>обов’язкове поле</u></span>
                <ul style="list-style: none">
                    <li>
                        <i>Детальніше:</i> користувач натискає на дату, відкривається календар та надає можливість вибрати необхідний день/місяць/рік.
                    </li>
                </ul>
            </li>
            <li>кнопка “Зареєструватися”</li>
            <li>кнопка "Назад”</li>
        </ul>
    <span>
        <i><u>Дії програми:</u></i><br>
        при натисканні на “Зареєструватися” програма перевіряє чи є такой користувач у системі (по логіну):
        <ul>
            <li>якщо є, користувач отримує повідомлення, що такий користувач вже зареєстрований та переадресує на сторінку авторизації</li> 
            <li>якщо немає, відбувається внесення користувача у систему та переадресує на сторінку авторизації</li> 
        </ul>
        при натисканні на "Назад” користувача повертає на сторінку авторизації
    </span>
</div><br><br>



<div id="page-auth">
    <b><u>Сторінка “Авторизація”</u></b><br>
    <span>
        <i><u>Опис:</u></i> 
        на сторінці “Aвторизація” знаходяться:
        <ul>
            <li>поле вводу “логін” - <span style="color: #85200c;"><u>обов’язкове поле</u></span>
                <ul style="list-style: none">
                    <li>
                        <i>Детальніше:</i> поле для логіну, куди користувач повинен ввести номер телефону, який вказував при реєстрації
                    </li>
                </ul>
            </li>
            <li>
                поле вводу "пароль” - 
                <span style="color: #85200c;"><u>обов’язкове поле</u></span>
            </li>
            <li>кнопка “Увійти”</li>
            <li>посилання “Реєстрація”</li>
        </ul>
    <span>
        <i><u>Дії програми:</u></i> 
        при натисканні “Увійти” програма перевіряє чи є такой користувач у системі:
        <ul>
            <li>якщо є, його перекидує на сторінку "Особистий кабінет"</li> 
            <li>якщо немає, користувач отримує повідомлення, що логін або пароль введений не правильно</li> 
        </ul>
    </span>
</div><br><br>



<div id="page-lk">
    <b><u>Сторінка “Особистий кабінет”</u></b><br>
    <span>
        <i><u>Опис:</u></i> 
        на сторінці “Особистий кабінет” знаходяться:
        <ul>
            <li>інформація, яку вносив користувач при 
                <a href="#page-registr">реєстрації</a>
            </li>
            <li>кнопка “Вийти”</li>
        </ul>
    <span>
        <i><u>Дії програми:</u></i> 
        <ul>
            <li>при натисканні натисканні кнопки “Вийти” користувач потряпляє на сторінку авторизації, тобто виходить зі свого кабінету.</li> 
        </ul>
    </span>
</div><br><br>



<div id="page-myVisits">
    <b><u>Сторінка “Мої записи”</u></b><br>
    <span>
        <i><u>Опис:</u></i> 
        на сторінці “Мої записи” знаходяться:
        <ul>
            <li>всі записи до лікарів</li>
            <li>кнопка "Записатись"</li>
        </ul>
    <span>
        <i><u>Дії програми:</u></i> 
        <ul>
            <li>при натисканні на "Записатись" відкривається сторінка <a href="#page-makeZap">"Створення запису"</a></li> 
        </ul>
    </span>
</div><br><br>

<div id="page-makeZap">
    <b><u>Сторінка “Створення запису”</u></b><br>
    <span>
        <i><u>Опис:</u></i> 
        на сторінці “Створення запису” знаходяться:
        <ul>
            <li>вибір лікаря
                <ul style="list-style: none">
                    <li>
                        <i>Детальніше:</i> випадаючий список, в якому користувач може обрати лікаря
                    </li>
                </ul>
            </li>
            <li>вибір дати
                <ul style="list-style: none">
                    <li>
                        <i>Детальніше:</i> користувач натискає на дату, відкривається календар та надає можливість вибрати необхідний день
                    </li>
                </ul>
            </li>
            <li>кнопка "Записатись"</li>
            <li>кнопка "Назад"</li>
        </ul>
    <span>
        <i><u>Дії програми:</u></i> 
        <ul>
            <li>при натисканні на "Записатись" створюється запис и потрапляє на сторінку <a href="#page-myVisits">"Мої записи"</a> у список</li> 
            <li>при натисканні на "Назад" користувача повертає на сторінку <a href="#page-myVisits">"Мої записи"</a></li> 
        </ul>
    </span>
</div><br>

<h3 style="text-align: center">Нефункціональні вимоги</h3>
<div>
    <i><u>Продуктивність:</u></i> 
    <div>- Система має бути здатна обробляти велику кількість запитів в невеликий проміжок часу без значних затримок.</div>
    <div>- Час відгуку системи має бути мінімальним для забезпечення зручності користувачів.</div>
    <br>
    <i><u>Інтерфейс:</u></i> 
    <div>Інтерфейс має бути інтуїтивно зрозумілим та простим у використанні для користувача.</div>
    <br>
    <i><u>Масштабованість:</u></i> 
    <div>- Інтерфейс має бути інтуїтивно зрозумілим та простим у використанні для користувача</div>
    <div>- Система має бути готова до додавання нових функцій</div>
    <div>- Архітектура системи повинна бути гнучкою та розширюваною.</div>
    <br>
    <i><u>Мова програмування:</u></i> 
    <div>- Інтерфейс має бути інтуїтивно зрозумілим та простим у використанні для користувача</div>
    <div>- Система має бути готова до додавання нових функцій</div>
    <div>- Архітектура системи повинна бути гнучкою та розширюваною.</div>
    <br>
    <i><u>Залежності:</u></i> 
    <div>Використання фреймворку Qt для створення додатку</div>
    <br>
    <i><u>Обробка винятків та помилок:</u></i> 
    <div>Програма повинна включати обробку винятків та помилок для запобігання аварійного завершення роботи та надавати користувачу інформацію про помилку.</div>
    <br>
    <i><u>Надійність</u></i> 
    <div>Програма повинна бути стійкою до помилок та відновлювати свою роботу після непередбачуваних ситуацій.</div>
</div>

<h2 style="text-align: center">Про команду</h2>
<b>Назва команди</b>: Jundev<br><br>
<div>У команді є шість ролей:
<ul>
    <li>Team Lead - Денис Сопко</li>
    <li>Project Manager - Александр Клевцов</li>
    <li>Scrum-майстер - WhatIsLove Філіппов</li>
    <li>Тестувальник - Алексей Журавський</li>
    <li>Дизайнер - Кирило Кухта</li>
    <li>Аналітик - Анастасія Москальова</li>
</ul>
</div>
