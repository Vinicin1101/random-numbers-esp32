# Medidor de Entropia para Geração de Números Aleatórios

O ADC do ESP32 pode ser usado para capturar ruído analógico (variação de tensão) e gerar números aleatórios de alta entropia.

## Funcionamento
O código utiliza o ADC em modo **one-shot** para capturar pequenas flutuações na tensão como fonte de entropia. Cada amostra é processada com o operador XOR bit a bit para reduzir padrões previsíveis e aumentar a complexidade.

## Requisitos
- **Placa ESP32** (ou ESP32-S3, dependendo do seu hardware)
- **ESP-IDF 5.5**

## Instalação
1. Clone este repositório:
   ```sh
   git clone https://github.com/Vinicin1101/random-numbers-esp32.git
   cd random-numbers-esp32
   ```
2. Compile o projeto:
   ```sh
   idf.py build
   ```
3. Flash na placa:
   ```sh
   idf.py -p /dev/ttyUSB0  flash
   ```

## Licença
Este projeto está sob a licença MIT.
