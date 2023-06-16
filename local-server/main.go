package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
)

func main()  {
	http.HandleFunc("/", HelloServer)
	http.ListenAndServe(":8080", nil)
}

func HelloServer(w http.ResponseWriter, r *http.Request)  {
	body, _ := ioutil.ReadAll(r.Body)
	log.Printf("Body: %v", string(body))
	fmt.Fprint(w, "Hello there from IOT_SERVER")
}