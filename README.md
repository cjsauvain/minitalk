# minitalk

> Projet réalisé dans le cadre du cursus de l’école 42.  

## 📌 Objectif

> Implémentation d’un système de communication entre deux programmes (serveur, client) Unix à l’aide de signaux (`SIGUSR1`, `SIGUSR2`).
> Créer un serveur et un client capables de communiquer en envoyant des **chaînes de caractères bit par bit**.  
> L’objectif est de comprendre la transmission d’informations via des signaux.

## ✅ Prérequis

- Compilateur C

## 🚀 Compilation && Execution

```bash
make

./server
  <PID>   (stdout)

./client <PID> <message to send>
```

## 🧠 Concepts abordés

- Gestion des signaux, dont `SIGUSR1` et `SIGUSR2`
- Communication inter-processus
- Encodage binaire
