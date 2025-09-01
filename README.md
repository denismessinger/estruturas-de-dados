# Estruturas de Dados em C

Este repositório foi criado para **estudos de Estruturas de Dados em C**.
Com atividades e exemplos feitos durante a disciplina de **Estruturas de Dados**.
Cada pasta contém implementações e exemplos práticos de diferentes estruturas.

## 📚 Estruturas
- **Stack (Pilha)**
  - Implementação **estática** stack_example (usando vetor fixo).
  - Implementação **dinâmica** dynamic_stack_example (usando lista encadeada).

A pilha segue a regra **LIFO (Last In, First Out)**, ou seja, o último elemento inserido é o primeiro a ser removido.

---

## ⚙️ Compilação e execução

### 🔹 Usando Code::Blocks
1. Abra o Code::Blocks.
2. Crie um novo projeto do tipo **Console Application (C)**.
3. Copie o código da pilha para o arquivo `main.c`.
4. Compile e execute com **Build & Run (F9)**.

---

### 🔹 Usando o terminal com `gcc`
Se estiver no Linux, Mac ou com MinGW no Windows:

```bash
# Compilar
gcc main.c -o pilha

# Executar
./pilha
