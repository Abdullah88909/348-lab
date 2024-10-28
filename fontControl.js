function applyStyle() {
    const paragraph = document.getElementById("styledParagraph");
    const borderWidth = document.getElementById("borderWidth").value;
    const rgbColor = document.getElementById("rgbColor").value;

    paragraph.style.borderWidth = `${borderWidth}px`;
    paragraph.style.borderColor = `rgb(${rgbColor})`;
}
