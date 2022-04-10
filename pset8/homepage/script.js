document.addEventListener("DOMContentLoaded", () => {
    document.querySelector("#submited").onclick = () => {
    document.querySelector(".message").innerHTML = "";
    document.querySelector(".form").innerHTML = "";
    document.querySelector("#change_reason").innerHTML = "for helping us make our site better by suggesting us."
    }
})