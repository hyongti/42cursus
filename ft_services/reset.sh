kubectl delete -f ./srcs/yaml/grafana.yml
eval $(minikube docker-env)
docker rmi grafana_service

docker build ./srcs/grafana/ -t grafana_service
kubectl apply -f ./srcs/yaml/grafana.yml