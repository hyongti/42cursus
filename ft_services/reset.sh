kubectl delete -f ./srcs/yaml/mysql.yml
eval $(minikube docker-env)
docker rmi mysql_service

docker build ./srcs/mysql/ -t mysql_service
kubectl apply -f ./srcs/yaml/mysql.yml
