const sharp = require('sharp');
const fs = require('fs');
const path = require('path');

/**
 * Converts an SVG file to PNG with specified dimensions or defaults to 32x32.
 * @param {string} inputFile - Name of the SVG file in the current directory.
 * @param {number} [outputHeight=32] - Desired height of the output PNG (default: 32).
 * @param {number} [outputWidth=32] - Desired width of the output PNG (default: 32).
 * @returns {Promise<void>} - A promise that resolves when the file is saved.
 */
async function convertSvgToPng(inputFile, outputHeight = 32, outputWidth = 32) {
    const inputPath = path.resolve(__dirname, inputFile);
    const outputPath = path.resolve(__dirname, path.basename(inputFile, '.svg') + '.png');
    
    if (!fs.existsSync(inputPath)) {
        throw new Error("Input file does not exist.");
    }
    
    const svgData = fs.readFileSync(inputPath);
    
    await sharp(svgData)
        .resize({ height: outputHeight, width: outputWidth })
        .toFormat('png')
        .ensureAlpha()  // Ensure alpha channel for RGBA format
        .png({ force: true })  // 8 bits per RGBA channel
        .toFile(outputPath);

    console.log(`${path.basename(outputPath)} ${outputWidth} ${outputHeight}`);
}

// Example Usage:
// Run with specified dimensions or defaults to 32x32
const args = process.argv.slice(2);  // Get command line arguments
const [inputFile, width, height] = args;

convertSvgToPng(inputFile, Number(height) || 32, Number(width) || 32)
    .then(() => console.log("Conversion completed successfully"))
    .catch(err => console.error("Error during conversion:", err));
