import json
import re
import subprocess

print("--- 1. JSON (Configurations) ---")
# Settings are often in .json files.
# Convert line into dict.
raw_json_string = '{"gnb_id": "GNB_01", "is_active": true, "max_ues": 100}'

# Магия: loads (Load String) мгновенно делает из текста рабочий словарь!
config = json.loads(raw_json_string)
print(f"ID Базовой станции: {config['gnb_id']}, Лимит: {config['max_ues']}")


print("\n--- 2. Модуль RE (Регулярные выражения) ---")
# Представь, что симулятор выплюнул огромный "грязный" лог.
# Нам нужно вытащить оттуда все ID устройств формата "UE_число".
dirty_log = "09:00 boot ok. 09:01 connected UE_102. 09:05 crash on UE_9999! bye."

# Шаблон поиска: r"UE_\d+" означает "найди буквы UE_ и следом любую цифру (\d) один или много раз (+)"
found_devices = re.findall(r"UE_\d+", dirty_log)
print(f"Найденные устройства: {found_devices}")


print("\n--- 3. Модуль SUBPROCESS (Запуск C++ кода) ---")
# Это самое главное! Как Python управляет симулятором? Он запускает его как процесс в терминале.
# Представь, что вместо системной команды "echo" здесь путь к твоему скомпилированному C++ симулятору: "./ue_simulator.exe"
# capture_output=True перехватывает то, что C++ вывел бы в консоль (std::cout).
result = subprocess.run(
    ["echo", "CRITICAL_5G_DATA_PROCESSED"], capture_output=True, text=True)

# Печатаем то, что вернула наша "внешняя" программа
print(f"Симулятор ответил: {result.stdout.strip()}")
