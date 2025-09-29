FROM debian:stable-slim

# Installation de nginx
	# Mise à jour des paquets
	RUN apt-get update && apt-get full-upgrade -y

	# Installation des dépendances nginx
	RUN  apt-get install curl gnupg2 ca-certificates lsb-release debian-archive-keyring procps iproute2 -y

	# Téléchargement des clés gpg pour télécharger nginx depuis apt
	RUN curl https://nginx.org/keys/nginx_signing.key | gpg --dearmor \
		| tee /usr/share/keyrings/nginx-archive-keyring.gpg >/dev/null

	# Inscription des clés dans les registres
	RUN	echo "deb [signed-by=/usr/share/keyrings/nginx-archive-keyring.gpg] \
		http://nginx.org/packages/debian `lsb_release -cs` nginx" \
		| tee /etc/apt/sources.list.d/nginx.list

	# Mise à jour avec les nouvelles sources, et installation de nginx depuis celles-ci
	RUN  apt-get update;	 apt-get install nginx -y


# Configuration de nginx
	# Certificat auto-signé pour ssl
	COPY ./conf/ssl/certs/nginx-selfsigned.crt /etc/ssl/certs/nginx-selfsigned.crt

	# Clé privée du certificat auto-signé
	COPY ./conf/ssl/private/nginx-selfsigned.key /etc/ssl/private/nginx-selfsigned.key

	# Configuration de nginx pour chargé la config TLSv1.3
	COPY ./conf/snippets/self-signed.conf /etc/nginx/snippets/self-signed.conf

	# Configuration de nginx pour paramétrer la config TLSv1.3
	COPY ./conf/snippets/ssl-params.conf /etc/nginx/snippets/ssl-params.conf

	COPY ./conf/default.conf /etc/nginx/conf.d/default.conf


# Exposition des ports 80,443 sur le réseau
	EXPOSE 80
	EXPOSE 443

# Démarrage de nginx en frontground
CMD ["nginx", "-g", "daemon off;"]