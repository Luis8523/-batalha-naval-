# 🚢 Batalha Naval com Habilidades Especiais

Projeto final do módulo de vetores e matrizes: uma versão turbinada de **Batalha Naval em C**, com habilidades especiais e áreas de efeito dinâmicas desenhadas diretamente no tabuleiro!

---

## 🎯 Descrição

Simula a clássica Batalha Naval com um toque estratégico: **três habilidades especiais** sobrepõem matrizes no tabuleiro, afetando áreas distintas com visual no terminal.

**Habilidades disponíveis:**

- 🔺 **Cone** – atinge área triangular para baixo
- ✝️ **Cruz** – atinge linha e coluna a partir do centro
- ♦️ **Octaedro** – forma losangular com alcance radial

---

## 💡 Conceitos aplicados

- Vetores e matrizes 2D
- Laços aninhados e condicionais
- Lógica de sobreposição com validação de limites
- Exibição gráfica no terminal usando caracteres ASCII
- Código limpo e bem documentado

---

## 🧩 Exemplo visual

Legenda:
- `~` = água (`0`)
- `#` = navio (`3`)
- `*` = área afetada (`5`)

```
     0  1  2  3  4  5  6  7  8  9 
 0 | *  *  #  ~  ~  ~  ~  ~  ~  ~ 
 1 | *  #  #  #  ~  ~  ~  ~  ~  ~ 
 2 | #  #  #  ~  ~  ~  ~  ~  ~  # 
 3 | ~  ~  ~  ~  ~  ~  ~  ~  #  ~ 
 4 | ~  ~  #  ~  ~  #  ~  ~  ~  ~ 
 5 | ~  ~  #  ~  *  *  *  ~  ~  ~ 
 6 | ~  ~  #  ~  ~  #  ~  ~  ~  ~ 
 7 | ~  ~  ~  ~  ~  ~  *  *  *  ~ 
 8 | ~  ~  ~  ~  ~  ~  ~  *  ~  ~ 
 9 | ~  ~  ~  ~  ~  ~  ~  ~  ~  ~ 
```

---

## ⚙️ Como compilar e executar

```bash
gcc batalha_naval.c -o batalha_naval
./batalha_naval
```

---

## ✍️ Autor

**Luis**  
[GitHub: @Luis8523](https://github.com/Luis8523)

Desenvolvido como desafio final de lógica com vetores e matrizes 🚀

---
