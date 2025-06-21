#include <Globals.hpp>
#include <SpikeWall.hpp>

SpikeWall::SpikeWall(bool isLeft) : isLeftWall(isLeft) {
    generate();
}

void SpikeWall::generate() {
    spikes.clear();
    constexpr int NUM_SPIKES = 6;
    constexpr float SPACING = HEIGHT / (NUM_SPIKES + 2);
    constexpr float GAP_SIZE = 120.f;

    float gapCenter = rand() % (HEIGHT - 150) + 75;

    for(int i = 0; i < NUM_SPIKES; ++i) {
        float y = SPACING * (i + 1);
        if(y < gapCenter - GAP_SIZE/2 || y > gapCenter + GAP_SIZE/2) {
            spikes.push_back(createSpike(y));
        }
    }
}

void SpikeWall::draw(sf::RenderWindow& window) const {
    for(const auto& spike : spikes) window.draw(spike);
}

bool SpikeWall::checkCollision(const sf::FloatRect& bounds) const {
    for(const auto& spike : spikes) {
        if(spike.getGlobalBounds().intersects(bounds)) return true;
    }
    return false;
}

sf::ConvexShape SpikeWall::createSpike(float y) const {
    sf::ConvexShape spike;
    spike.setPointCount(3);
    
    if(isLeftWall) {
        spike.setPoint(0, {SPIKE_LENGTH, y});
        spike.setPoint(1, {0, y - 25});
        spike.setPoint(2, {0, y + 25});
    } else {
        spike.setPoint(0, {WIDTH - SPIKE_LENGTH, y});
        spike.setPoint(1, {WIDTH, y - 25});
        spike.setPoint(2, {WIDTH, y + 25});
    }
    
    spike.setFillColor(sf::Color(255, 50, 50));
    return spike;
}
