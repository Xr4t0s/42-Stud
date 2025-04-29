# minishell

💻 Créer un shell simplifié capable d'exécuter des commandes Unix.

## Objectifs
- Implémenter un interpréteur de commandes minimaliste
- Gérer les pipes (`|`), redirections (`>`, `<`, `>>`, `<<`)
- Supporter les builtins (`cd`, `echo`, `export`, `unset`, `env`, `exit`)
- Gérer correctement les signaux (`CTRL+C`, `CTRL+D`, `CTRL+\`)
- Respecter les règles de gestion de la mémoire (pas de leaks)

## Concepts clés
- Processus et fork/execve
- Pipes et redirections
- Gestion fine des signaux
- Parsing d'input utilisateur
- Gestion d'environnements (`env`)

## Sujet du projet
Vous pouvez consulter le sujet officiel ici : [📑 Sujet PDF](./minishell.subject.pdf)
