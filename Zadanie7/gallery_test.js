document.addEventListener("DOMContentLoaded", function () {
    var currentPage = 1;
    var totalPages = document.getElementsByClassName("image-group").length;

    document.getElementById("prev").addEventListener("click", function () {
        if (currentPage > 1) {
            currentPage--;
            updateGallery();
        }
    });

    document.getElementById("next").addEventListener("click", function () {
        if (currentPage < totalPages) {
            currentPage++;
            updateGallery();
        }
    });

    function updateGallery() {
        var imageGroups = document.getElementsByClassName("image-group");
        for (var i = 0; i < imageGroups.length; i++) {
            imageGroups[i].style.display = "none";
        }

        if (imageGroups[currentPage - 1]) {
            imageGroups[currentPage - 1].style.display = "flex";
        }

        document.getElementById("current-page").textContent = currentPage;
        document.getElementById("total-pages").textContent = totalPages;
    }

    updateGallery();
});


