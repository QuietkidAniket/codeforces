from PIL import Image, ImageDraw, ImageFont
import os

def generate_welcome_image(record, template_path, output_dir, font_path, font_size=40):
    """
    Generates a personalized welcome image for a given intern record.

    Args:
        record (dict): A dictionary with keys like Name, Email Address, Joining Date, Mentor Name, etc.
        template_path (str): Path to the template image.
        output_dir (str): Directory where the generated image will be saved.
        font_path (str): Path to the font file.
        font_size (int): Font size for the text.
    """

    os.makedirs(output_dir, exist_ok=True)
    
    # Load template
    template = Image.open(template_path)
    img = template.copy()
    draw = ImageDraw.Draw(img)
    font = ImageFont.truetype(font_path, font_size)

    # Construct the welcome message
    name = record["Name"]
    # email = record["Email Address"]
    joining_date = record["Joining Date"]
    mentor_name = record["Mentor Name"]
    department = record.get("Department", "N/A")
    duration = record.get("Internship Duration (Months)", "N/A")
    
    # Add text to the image
    welcome_text = f"Welcome, {name}!\n"
    details = f"\n\nJoining Date: {joining_date}\n\n\nMentor: {mentor_name}\n\n\nDepartment: {department}\n\n\nDuration: {duration} months"

    # Center the welcome message
    img_width, img_height = img.size
    welcome_width, welcome_height = draw.textbbox((0, 0), welcome_text, font=font)[2:]
    details_width, _ = draw.textbbox((0, 0), details, font=font)[2:]

    x_welcome = (img_width - welcome_width) // 2
    y_welcome = img_height // 2 - 100
    x_details = (img_width - details_width) // 2
    y_details = y_welcome + 60

    # Draw text
    draw.text((x_welcome, y_welcome), welcome_text, font=font, fill="black")
    draw.text((x_details, y_details), details, font=font, fill="black")

    # Save the image
    output_path = os.path.join(output_dir, f"welcome_{name.replace(' ', '_').lower()}.png")
    img.save(output_path)




""" ~~~~~~~~~~~~~ TEST ~~~~~~~~~~~~~~~~~~ """

# Example usage
record_example = {
    "Name": "Alice Johnson",
    "Email Address": "alice.johnson@example.com",
    "Joining Date": "2025-01-10",
    "Mentor Name": "Bob Smith",
    "Department": "Engineering",
    "Internship Duration (Months)": 6
}

""" Paths """
template_path = "welcome_template.png"  # Replace with the actual template path
output_dir = "intern_welcome_images/"
os.makedirs(output_dir, exist_ok=True)

# Font settings
font_path = "/Library/Fonts/SF-Mono-Medium.otf"  
font_size = 40

# Load template
template = Image.open(template_path)

generate_welcome_image(record_example, template_path, output_dir, font_path)



